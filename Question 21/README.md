Nene invented a new game based on an increasing sequence of integers a1, a2,..., ak.
n this game, initially n players are lined up in a row. In each of the rounds of this game, the following happens:
• Nene finds the a1-th, a2-th, ..., a-th players in a row. They are kicked out of the game simultaneously. If the i-th player in a row should be kicked out, but there are fewer than i players in a row, they are skipped.
Once no one is kicked out of the game in some round, all the players in a row. They are kicked out of the game simultaneously. If the i-th player in a row should be kicked out, but there are fewer than i players in a row, they are skipped.
Once no one is kicked out of the game in some round, all the players that are still in the game are declared as winners.
For example, consider the game with a = [3, 5] and n = 5 players. Let the players be named player A, player B,..., player E in the order they are lined up initially. Then,
• Before the first round, players are lined up as ABCDE. Nene finds the 3-rd and the 5-th players in a row. These are players C and E. They are kicked out in the first round.
⚫ Now players are lined up as ABD. Nene finds the 3-rd and the 5-th players in a row. The 3-rd player is player D and there is no 5-th player in a row. Thus, only player D is kicked out in the second round.
⚫ In the third round, no one is kicked out of the game, so the game ends after this round.
⚫ Players A and B are declared as the winners.
, nq and you should answer
Nene has not yet decided how many people would join the game initially. Nene gave you q integers n1, n2,...,? he following question for each 1 ≤ i ≤q independently:
• How many people would be declared as winners if there are n; players in the game initially?
