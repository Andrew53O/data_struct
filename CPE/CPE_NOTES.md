

# 1 star
list: https://cpe.cse.nsysu.edu.tw/environment.php#starList

10/23/2025: 38/49

from start to what is the probablity

## Some word needs to memorize
`#include <bits/stdc++.h>`
ios::sync_with_stdio(fals); 
cin.tie(null);


## Tricky problem

### Sort! Sort!! Sort!!!
- sort custom function

### GCD
- need to understand euclidean algorithm 

Note: when two lengths are both multiples of the same tiny piece, they are called *commensurable*. 

Euclidean algorithm tells that gcd(a,b) = gcd(b, remainder(a,b)), for b is  not 0

proof = a = qb + r, any divisor of 2 of these terms must divide all 3 terms, 
so a, b and b, have the same divisors 

### All you need is love 

Need to add these 2 lines, otherwise it won't pass 

ios_base::sync_with_stdio(false); cuts the synchronization with C's I/O.

cin.tie(NULL); unties cin from cout, which stops the program from flushing the output buffer every time you ask for input.

### A mid summer nights dream

- **Mean** minimizes the sum of squared deviations:  
  $\displaystyle \min_A \sum (x_i - A)^2$

- **Median** minimizes the sum of absolute deviations:  
  $\displaystyle \min_A \sum |x_i - A|$


# Some useful library & function 

## cin
- cin can cin >> N >> eq >> value;   // with input:  N = 3 <br>
getting the value of 3 in the value variable

## Initialize vector
vector<bool> isComplete(5, false); 

### Vector 
`#include <vector>`
- back() return the last value
- void pop_back() just pop value, doens't return anything
- clear() clear the vector and keeps the allocated capacity
### 2d vector
vector<vector<char>> arr(h, vector<char>(w, '0');

## Data Structure

### Unordered Map
`#include <unordered_map>`
- find()
- insert() <br>
auto check = unorderedMap.insert(num);
check.first // the iterator
check.second // the boolean value of duplicate 

### Array (C style)
from #include algorithm <br>
fill(arr, arr + 128, 0);

### Deque (double ended queue)
`#include <deque>`
used like vector

- push_back(value): Adds an element value to the end of the deque. O(1) amortized. 
- push_front(value): Adds an element value to the beginning of the deque. O(1) amortized.
- pop_back(): Removes the last element from the deque. O(1).
- pop_front(): Removes the first element from the deque. O(1).
- operator[](index): Accesses the element at position index. Does not perform bounds checking. O(1).
- at(index): Accesses the element at position index. Does perform bounds checking, throws std::out_of_range if invalid. O(1).
- front(): Returns a reference to the first element. Undefined if deque is empty. O(1).
- back(): Returns a reference to the last element. Undefined if deque is empty. O(1).
- size(): Returns the number of elements currently in the deque. O(1).
- empty(): Returns true if the deque has no elements, false otherwise. O(1).


`#include <iomanip>`
- fixed 
- setprecision(x)

`#include <cmath>` 
- sqrt()
- ceil()
- floor()
- pow()
- abs() / fabs() <br>
abs(v[i] - v[i + 1])
- sin(), cos(), tan(), acos()

Find pi = acos(-1.0);

sin, cos, tan use radians
pi * radians = 180 degree

`#include <algorithm>`
- reverse()<br>
std::reverse(string.begin(), string.end())
, string.end());
- find() <br>
// Check if the "find" function reached the end without finding 'false'
bool all_true = (std::find(arr.begin(), arr.end(), false) == arr.end());
- fill() <br>
std::fill(arr.begin(), arr.end(), false); // fill all values to false
- min(), max() Comparing two specific known values or variables.
- min_element(), max_element() returning iterator <br>
auto min_it = min_element(v.begin(), v.end());
    cout << "Min value: " << *min_it << endl; // Output: 1

    // Find the maximum element
    auto max_it = max_element(v.begin(), v.end());
    cout << "Max value: " << *max_it << endl; // Output: 9
- sort() custom function rule: 
Comparator rule: custom(int &a, int &b)
TRUE → a comes before b
FALSE → a stays after b

`#include <string>`
- stoi() <br>
- getline() <br>
getline(cin, str) <br>
note: **getline() reads until newline — including leading whitespace if present.
So when switching between them, always clean the buffer with cin.ignore().**

- clear() <br>
- to_string(num) // convert num pto string

`#include <sstream>`
to convert string as if it were input coming from the console <br>
stringstream ss(input_string); <br> or
ss.str(input_string);


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


## Finding a prime number

- for loop through for (int i = 3; i * i <= n; i+=2) if (n % i == 0) return false

# Some Concept

- Subsequence: A smaller string made by deleting zero or more characters from a bigger string, without changing the order of the remaining characters.<br>Example: "ace" is a subsequence of "abcde".

- Permutation: A rearrangement of the letters in a string.<br>
Example: Permutations of "no" are "no" and "on"


# Data Type

| Type              | Typical Size      | Typical Range                    | Key Feature                            |
| ----------------- | ----------------- | -------------------------------- | -------------------------------------- |
| `int`             | 32 bits           | ~ -2.1 billion to +2.1 billion   | Default, general purpose.              |
| `unsigned int`    | 32 bits           | ~ 0 to +4.2 billion              | Non-negative values only.              |
| `long int`        | 32 or 64 bits     | Varies by system                 | Larger than or equal to `int`.         |
| `long long int`   | 64 bits           | ~ -9 quintillion to +9 quintillion | For very large integer values.         |


