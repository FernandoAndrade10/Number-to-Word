//Fernando Andrade
//Visual Studio 2019

#include <iostream>
#include <string>

using namespace std;

void numConverter(int arr[], int size, int tnths[], int num2) {
	string singles[10] = { "null", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string tens[10] = { "null", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	string tenths[10] = { "null" , "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	string hundred = "hundred";
	string thousand = "thousand";

	if (size == 4)
	{
		cout << num2 << " is: " << singles[arr[0]] << " " << thousand << endl;
	}

	if (size == 3)
	{
		// Check multiples of 100
		if (arr[1] == 0 && arr[2] == 0)
		{
			cout << num2 << " is: " << singles[arr[0]] << " " << hundred << endl;
		}

		if (tnths[0] == 1 && tnths[1] != 0)
		{
			cout << num2 << " is: " << singles[arr[0]] << " " << hundred << " " << tenths[tnths[1]] << endl;
		}

		if (tnths[1] == 0)
		{
			cout << num2 << " is: " << tens[tnths[0]] << endl;
		}

		if (tnths[0] != 1 && tnths[1] != 0)
		{
			cout << num2 << " is: " << singles[arr[0]] << " " << hundred << " " << tens[tnths[0]] << " " << singles[tnths[1]] << endl;
		}
	}

	if (size == 2)
	{
		// Check if it's 11-19
		if (tnths[0] == 1 && tnths[1] != 0)
		{
			cout << num2 << " is: " << tenths[tnths[1]] << endl;
		}

		// Check if its a multiple of ten
		if (tnths[1] == 0)
		{
			cout << num2 << " is: " << tens[tnths[0]] << endl;
		}

		// Check if its 21-99 exluding any numbers ending in 0
		if (tnths[0] != 1 && tnths[1] != 0)
		{
			cout << num2 << " is: " << tens[tnths[0]] << " " << singles[tnths[1]] << endl;
		}
	}

	if (size == 1)
	{
		cout << "////////////////////////" << endl;
		cout << num2 << " is: " << singles[arr[0]] << endl;
	}

}

int main() {
	int num = 0;

	cout << "Enter a number from 1 to 1000: ";
	cin >> num;

	cout << endl;

	int tmp[4] = {};
	int arr[4] = {};
	int j = 0;
	int size = 0;
	int tenths[2] = {};
	int num2 = num;

	// extract each digit in the input into an array
	//ex. input 123 gets stored in array as 321
	while (num > 0)
	{
		int digit = num % 10;
		num /= 10;

		tmp[j] = digit;

		j++;
		size++;
	}

	j = 0;

	//reverse the array from ex. 321 to user input 123
	for (int i = size - 1; i >= 0; i--)
	{
		arr[j] = tmp[i];

		j++;
	}

	// create an array containing only the last two digits
	//ex. 125 would get saved as 25 and 39 would get saved as 39
	for (int i = 0; i < size; i++)
	{
		if (size == 2)
		{
			tenths[i] = arr[i];
		}

		if (size == 3 && i > 0)
		{
			tenths[i - 1] = arr[i];
		}
	}


	numConverter(arr, size, tenths, num2);


	return 0;
}