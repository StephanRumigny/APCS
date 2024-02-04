# Simulatate a sports tournament

import csv
import sys
import random

# Number of simulations to run
N = 1000


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # get the filename from the command line arguments
    filename = sys.argv[1]

    # Read teams from the file
    teams = read_teams(filename)

    # store the count of each team's victories
    counts = {}

    # Simulate N tournaments and keep track of win counts
    for _ in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda t: counts[t], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def read_teams(filename):
    """Read teams into memory from file."""
    teams = []
    with open(filename) as f:
        reader = csv.DictReader(f)
        for row in reader:
            # Convert rating to int
            row["rating"] = int(row["rating"])
            teams.append(row)
    return teams


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    # Calculate the probability of team1 winning
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    # Return True if a random number is less than the calculated probability
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return the name of the winning team."""
    # Continue simulating rounds until there is only one team left
    while len(teams) > 1:
        teams = simulate_round(teams)

    # Return the name of the winning team
    return teams[0]["team"]


if __name__ == "__main__":
    main()
