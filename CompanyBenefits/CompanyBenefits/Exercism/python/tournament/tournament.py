from bisect import insort

def tally(rows):
    results = rows
    teams = {}
    top_score = 0

    for row in results:
        team1, team2, victory = row.split(';')
        for team in (team1, team2):
            if team not in teams:
                teams[team] = [0, 0, 0, 0, 0]
            teams[team][0] += 1
        if victory == 'win':
            teams[team1][1] += 1
            teams[team1][4] += 3
            teams[team2][3] += 1
        elif victory == 'loss':
            teams[team2][1] += 1
            teams[team2][4] += 3
            teams[team1][3] += 1
        else:
            teams[team1][2] += 1
            teams[team1][4] += 1
            teams[team2][2] += 1
            teams[team2][4] += 1
        top_score = max(teams[team1][4], teams[team2][4], top_score)

    rankings = {}
    for num in range(top_score+1):
        rankings[num] = []
    for team in teams:
        insort(rankings[teams[team][4]], team)

    table = ['Team                           | MP |  W |  D |  L |  P']
    for rank in rankings:
        for team in rankings[top_score-rank]:
            table_row = '{teamname: <30}'.format(teamname=team)
            for value in teams[team]:
                table_row += ' | '
                table_row += '{valuename: >2}'.format(valuename=value)
            table.append(table_row)
    return table
