

# 1 star
list: https://cpe.cse.nsysu.edu.tw/environment.php#starList

## Tricky problem

### Sort! Sort!! Sort!!!
- sort custom function


# Some useful library & function 

`#include <cmath>` 
- sqrt()
- ceil()
- floor()
- pow()
- abs() / fabs()

`#include <algorithm>`
- reverse()<br>
std::reverse(string.begin(), string.end())
, string.end());

- min(), max()

`#include <string>`
- stoi() <br>
- getline() <br>
getline(cin, str)
string to integer 
- clear() <br>

`#include <cctype>`
- tolower()
- toupper()

`#include <map>`
- find() <br>
.find(), if found it return pointer to the entry, if not returns a special iterator that pionst to the end of the map
auto it = example_map.find(c)
if (it != example_map.end()) // does not find
it -> first // for key value
it -> second // for value 

`#include <unordered_map>` 
unordered_map<char, char> decoder  = {{'x', 'a'}, ....} 
- decodder.at(x); // return a

Note: can't access unordered_map like an array 

# Some rules

## Divisibility Rules Quick Reference
---

* **Divisible by 2:** The last digit is even (0, 2, 4, 6, 8).

* **Divisible by 3:** The sum of the digits is divisible by 3.

* **Divisible by 4:** The number formed by the last two digits is divisible by 4.

* **Divisible by 5:** The last digit is 0 or 5.

* **Divisible by 6:** The number is divisible by **both 2 and 3**.

* **Divisible by 8:** The number formed by the last three digits is divisible by 8.

* **Divisible by 9:** The sum of the digits is divisible by 9.

* **Divisible by 10:** The last digit is 0.

* **Divisible by 11:** The **alternating sum** of the digits (e.g., $d_1 - d_2 + d_3 - \dots$) is divisible by 11.

* **Divisible by 13:** (Choose one method)
    * **Method A:** Repeatedly **add 4 times the last digit** to the rest of the number.
    * **Method B:** The **alternating sum of 3-digit blocks** (from right to left) is divisible by 13.


# Some Concept

- Subsequence: A smaller string made by deleting zero or more characters from a bigger string, without changing the order of the remaining characters.<br>Example: "ace" is a subsequence of "abcde".

- Permutation: A rearrangement of the letters in a string.<br>
Example: Permutations of "no" are "no" and "on"