#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin >> t; // Read the number of test cases
	while (t--) {
		int n; 
		cin >> n; // Read the length of the array
		map<int, int> mp; // Map to store the count of set bits at each position
		for (int i = 0; i < n; i++) { // Iterate over each element in the array
			int temp; 
			cin >> temp; // Read each element of the array
			for (int j = 0; j < 31; j++) { // Check each bit position (assuming 31 bits for integers)
				if (temp & (1 << j)) { // If the j-th bit is set in temp
					mp[j]++; // Increment the count of set bits at position j
				}
			}
		}
		int gcd = 0; // Variable to store the greatest common divisor of counts
		int f = 1; // Flag to check if gcd is still zero
		for (auto i : mp) { // Iterate over the map to calculate gcd
			f = 0; // Set flag to zero as we have non-zero counts
			if (gcd == 0) {
				gcd = i.second; // Initialize gcd with the first count
			} else {
				gcd = __gcd(gcd, i.second); // Calculate gcd of current gcd and count
			}
		}
		if (f) { // If flag is still set, print all indices
			for (int i = 0; i < n; i++) { // Output all indices from 1 to n
				cout << i + 1 << " ";
			}
			cout << "\n";
			continue; // Move to the next test case
		}

		vector<int> factors; // Vector to store factors of gcd
		for (int i = 1; i * i <= gcd; i++) { // Find all factors of gcd
			if (gcd % i == 0) {
				factors.push_back(i); // Add factor i
				if (i != gcd / i) // Avoid adding the square root twice
					factors.push_back(gcd / i); // Add the corresponding factor
			}
		}
		sort(factors.begin(), factors.end()); // Sort factors in increasing order
		for (int f : factors) { // Output all factors
			cout << f << " ";
		}
		cout << "\n"; // New line after each test case
	}
}

// Time Complexity (TC): O(n log a_i)
// Space Complexity (SC): O(log a_i + cubeRoot(n))
