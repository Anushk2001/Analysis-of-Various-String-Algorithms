# Optimisation-of-Pattern-Matching

Visit : [Documentation](https://drive.google.com/file/d/1AzBEZd2I72Sz0WjuPOL8ixdJeXt7eOcb/view?usp=sharing)

I have chosen this theme to ensure the correctness of these algorithms and
to learn deep mathematics behind these algorithms. I am desirous of
learning how the text searching in text editors work, how spell errors are
checked, etc. I will be analyzing the time and space complexities of the
algorithms used in these practical cases and also implement them for my
own satisfaction.


# Knuth Morris Pratt (K.M.P.) String matching Algorithm:
This algorithm is the most important algorithm for solving the problem of
string matching. It solves this problem in linear time and space complexity.
This algorithm improves the basic naive algorithm by not just going to the
next window blindly and redoing the same work. It skips a few windows
selectively and chooses the next window to check for the pattern by the
concept of Longest Proper Prefixes and Suffixes (L.P.S.) This involves
greedy and dynamic programming, programming paradigms. This
algorithm cleverly uses the properties of the longest proper prefix of a
string which is also a proper suffix for choosing the next window after a
deviation is detected in
the current processing window.

# Z Algorithm :
It is used to find the pattern as a substring in a string in O(n). KMP
Algorithm also does the same task at the same time complexity but Z
algorithm is quite more intuitive and easy to understand. It is commonly
applied in many applications like finding a phrase in a pdf or a virtual
dictionary. To accomplish this task a preprocessing stage occurs where we
trade space for time. We create a Z Array where Z[i] represents the longest
length of a substring starting at Z[i] which is also the prefix. To accomplish
this is the main aim to understand this algorithm. Rest follows quite easily
as we will see in this project. This approach also follows Dynamic
Programming as we are reusing the previously calculated results.

# Karp-Rabin Algorithm :
This algorithm is entirely different from the ones discussed. This algorithm
works on the concept of role hashing, which calculates the hash of one
window from the previous window in the order of constant time. Ideally or
theoretically, this hash function is collision-free as it works like a new
number system having 256 digits and a number can be represented only
in one way in a particular number system. But practically, a few collisions
may occur by applying a modulus on the hash value for preventing
arithmetic and space overflows. This method uses the hash of the
windows as the primary filter for detecting patterns thus reducing the need
of checking every window, unlike the naive algorithm.
