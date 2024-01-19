#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <math.h>
#include <chrono>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define ll long long

enum dir {
    u  = 0b10000,
    r  = 0b1000,
    dr = 0b100,
    dl = 0b10,
    l  = 0b1,
};

int dist = -1;
int get_dist() {
    if (dist != -1) return dist;

    cout << "app" << endl;
    cin >> dist;

    return dist;
}

int room_mask = 0;
void read_room_mask() {
    string s;
    cin >> s;

    room_mask = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') room_mask |= 1 << (s.size() - i - 1);
    }
}

dir last_dir;
void move(dir d) {
    switch (d)
    {
        case dir::u:  cout << "up";        break;
        case dir::l:  cout << "left";      break;
        case dir::dl: cout << "downleft";  break;
        case dir::dr: cout << "downright"; break;
        case dir::r:  cout << "right";     break;
    }

    cout << endl;
    read_room_mask();

    dist = -1;
    last_dir = d;
}

inline bool can_move(dir d) {
    return room_mask & d;
}

void gather_rooms(int d, int r, vector<bool>& room_exists, vector<vector<dir>>& room2path, vector<dir>& curr_path) {
    room_exists[r] = true;
    room2path[r] = curr_path;

    if(d <= 3) {
        if(can_move(dir::dl)) {
            move(dir::dl);
            curr_path.push_back(dir::dl);

            gather_rooms(d + 1, r * 2 + 1, room_exists, room2path, curr_path);

            move(dir::u);
            curr_path.pop_back();
        }

        if(can_move(dir::dr)) {
            move(dir::dr);
            curr_path.push_back(dir::dr);

            gather_rooms(d + 1, r * 2 + 2, room_exists, room2path, curr_path);

            move(dir::u);
            curr_path.pop_back();
        }
    }
}

int perform_start() {
    int max_rooms = (1 << 4) - 1;

    vector<bool> room_exists(max_rooms, false);
    vector<vector<dir>> room2path(max_rooms, vector<dir>());
    vector<dir> _curr_path;
    gather_rooms(1, 0, room_exists, room2path, _curr_path);

    vector<vector<int>> dist_room2room(max_rooms, vector<int>(max_rooms, -1));
    for(int start = 0; start < max_rooms; start++) {
        queue<pair<int, int>> doorq, stairq;
        set<int> visited;

        doorq.push({ start, 0 });
        visited.insert(start);

        while(!doorq.empty() || !stairq.empty()) {
            queue<pair<int, int>>& q = !doorq.empty() ? doorq : stairq;
            auto [r, dist] = q.front();
            q.pop();

            dist_room2room[start][r] = dist;

            vector<pair<int, queue<pair<int, int>>&>> neighs;
            if(r != 0) neighs.push_back({ r / 2, stairq });
            if(__builtin_clz((r - 1) + 1) == __builtin_clz(r + 1)) neighs.push_back({ r - 1, doorq });
            if(__builtin_clz((r + 1) + 1) == __builtin_clz(r + 1)) neighs.push_back({ r + 1, doorq });
            if((r * 2 + 1) < (1 << 4)) neighs.push_back({r * 2 + 1, stairq });
            if((r * 2 + 2) < (1 << 4)) neighs.push_back({r * 2 + 2, stairq });

            for(auto [r, nq] : neighs) {
                if(!room_exists[r] || visited.find(r) != visited.end()) continue;

                visited.insert(r);
                nq.push({ r, dist + 1 });
            }
        }
    }

    for(int r1 = 0; r1 < max_rooms; r1++) {
        if(!room_exists[r1]) continue;

        for(int r2 = r1 + 1; r2 < max_rooms; r2++) {
            if(!room_exists[r2]) continue;

            map<int, int> diff2room;
            bool valid = true;
            for(int target_r = (1 << 3); target_r < (1 << 4); target_r++) {
                if(!room_exists[target_r]) continue;

                int diff = dist_room2room[r1][target_r] - dist_room2room[r2][target_r];

                if(diff2room.find(diff) != diff2room.end()) {
                    valid = false;
                    break;
                }

                diff2room[diff] = target_r;
            }

            if(!valid) continue;

            for(dir d : room2path[r1]) move(d);
            int dist1 = get_dist();
            while(can_move(dir::u)) move(dir::u);

            if(dist1 <= 100) return get_dist();

            for(dir d : room2path[r2]) move(d);
            int dist2 = get_dist();
            while(can_move(dir::u)) move(dir::u);

            int diff = dist1 - dist2;
            int start_room = diff2room[diff];

            for(dir d : room2path[start_room]) move(d);
            return dist1 - dist_room2room[r1][start_room];
        }
    }

    throw exception();
}

int main() {
    read_room_mask();

    while(can_move(dir::u)) {
        move(dir::u);
    }

    int levels_left = perform_start();
    while(levels_left > 0) {
        if(can_move(dir::dl) && can_move(dir::dr) && levels_left > 1) {
            int prev_dist = levels_left;

            bool rooms2below[4] = { 0 };

            move(dir::dl);
            rooms2below[0] = can_move(dir::dl);
            rooms2below[1] = can_move(dir::dr);

            move(dir::r);
            rooms2below[2] = can_move(dir::dl);
            rooms2below[3] = can_move(dir::dr);

            bool left_empty = !rooms2below[0] && !rooms2below[1];
            bool right_empty = !rooms2below[2] && !rooms2below[3];

            bool left_full = rooms2below[0] && rooms2below[1];
            bool right_full = rooms2below[2] && rooms2below[3];
            
            dir move_dir;
            if(left_empty || right_empty) {
                if(right_empty) move(l);
                levels_left--;

                continue;
            } if(left_full || right_full) {
                if(right_full) {
                    move_dir = dir::l;
                    move(dir::dr);
                } else {
                    move_dir = dir::r;
                    move(dir::l);
                    move(dir::dl);
                }
            } else {
                move_dir = dir::l;

                if(can_move(dir::dr)) move(dir::dr);
                else move(dir::dl);
            }

            int expected_dist = levels_left - 2;
            
            if(get_dist() == expected_dist) {  }
            else if(get_dist() == expected_dist + 1) { move(move_dir); }
            else if(get_dist() == expected_dist + 2) { move(move_dir); move(move_dir); }
            else { 
                move(dir::u); 
                move(move_dir);

                dir down_move_dir = move_dir == dir::r ? dir::dr : dir::dl;
                dir other_down_move_dir = down_move_dir == dir::dl ? dir::dr : dir::dl;

                if(can_move(down_move_dir)) move(down_move_dir);
                else move(other_down_move_dir);
            }

            levels_left -= 2;
        } else {
            if(can_move(dir::dl)) move(dir::dl);
            else move(dir::dr);

            levels_left--;
        }
    }

    if(get_dist() != 0) {
        if(last_dir == dir::dl) move(dir::r);
        else if(last_dir == dir::dr) move(dir::l);
    }

    cout << "here" << endl;
}