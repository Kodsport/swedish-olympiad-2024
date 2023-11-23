#!/usr/bin/python3

def optimal_tid(n, t, buildings):
    time_to_win = float('inf')  # Initialt sätt tid till oändlighet

    # Sortera byggnaderna efter produktion per pickles per sekund (pi)
    sorted_buildings = sorted(buildings, key=lambda x: x[0], reverse=True)

    # Få maximal produktion per sekund genom att köpa byggnader med högsta pi först
    current_production = 0
    current_pickles = 0
    for building in sorted_buildings:
        current_production += building[0]
        time_to_buy_building = (building[1] - current_pickles) / current_production

        # Kolla om det är värt att köpa byggnaden jämfört med att köpa Megapickeln
        if time_to_buy_building < 0:  # Ändring här för att hantera byggnader som redan är tillräckligt billiga
            time_to_buy_building = 0

        if time_to_buy_building < time_to_win:
            current_pickles += time_to_buy_building * current_production
            time_to_win = min(time_to_win, time_to_buy_building)
        else:
            break  # Om det inte är värt att köpa byggnaden, bryt loopen

    # Kolla om det är snabbare att köpa Megapickeln direkt
    time_to_win = min(time_to_win, t / current_production)

    return int(time_to_win)

# Läs in input från användaren
n = int(input("Antal byggnader ? "))
t = int(input("Kostnad av Megapickeln ? "))

buildings = []
for i in range(n):
    pi, ci = map(int, input(f"Produktionshastighet och pris för byggnad {i + 1} ? ").split())
    buildings.append((pi, ci))

# Anropa funktionen och skriv ut svaret
result = optimal_tid(n, t, buildings)
print("Svar:", result)