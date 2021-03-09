# Space-and-Earth

1. Space
Given that there is a solar system in which several planets revolve on the same orbit around the system's star, X has traveled from planet to planet and knows how much fuel is needed to get from one planet to the next one.
How many planets could he visit if he would start a journey with limited fuel, from a particular planet, going either only clockwise or only counter-clockwise on orbit?

2. Earth
There lies a great unattended trasure on one of the remote corners of the solar system. X would like to move it back to Earth by travelling on the direct path from his current position, but his ship won't make it to the final destination. Given that there are S shipyards, where he can exchange for a fee his current spaceship with a different one, X would like to know if it is possible to reach his destination and if yes, what's the cheapest way to do it.


Solutions
1. Space
After reading how many planets there are on the orbit and the number of queries, I
thought about storing the distances from the second line in an array called planets
and then doubling it. This array represents the clockwise traversal. The same goes 
for the second array entitled iplanets, which represents the counter-clockwise
traversal of the orbit. 
By doubling both arrays and then transforming them so that
each position i does not represent the fuel cost from planet i to planet i+1, but 
rather the fuel cost from planet 0 to planet i+1, I can make sure that when doing
a binary search in the arrays, I will be able to easily find the number of planets
reached (thus simulating an orbit). After finding out the solutions for both 
traversals - clockwise and counter-clockwise - the final answer will consist in the
maximum of the two.

Time Complexity - O ( t * n * log2(n) )
Space Complexity - O (n)

*I noticed that N has an upper limit, that being 10000 and that we have several tests 
exceeding the limit, therefore I added a command in the code that checks if N > 10000 
and if so, it ends the program. However, the command is marked as a comment.s


2. Earth
In order to solve this problem I approached a greedy way of thinking. Keeping in mind
that I am only interested in the minimal cost of getting from the source to the 
destination, I will only compute the cost for the S shipyards and the destination.
By using an increasing ordered set of the form (cost, range), I will store for every
spaceship the minimum cost of reaching it as well as its own cost (i.e. the minimum 
cost of reaching the shipyard and exchanging my spaceship), as well as the maximum
range that can be travelled with it (read from the file). 
When I receive a new spaceship, first I eliminate from the set all spaceships that could
not reach the new one, then I extract from the set the spaceship that has the minimum
cost (because now I can reach my new spaceship with all the spaceships that remained
in the set, but I am only interested in the cheapest one), after which I introduce
the new spaceship in the set.
The answer will then be either -1, if the destination could not be reached, or
the minimum cost to reach the destination, stored in the first element of the set.

Time Complexity - O (S * log2(S) )
Space Complexity - O (S)
