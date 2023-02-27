class Solution
{
	public:
		int maxProfit(vector<int> &prices)
		{
			int sum = 0;
			//If the number of element in the array are zero or one just return zero.
			if (prices.size() == 1 or prices.size() == 0)
			{
				return 0;
			}

			//Traverse the array and compare the consecutive two elements .
			for (int i = 0; i < prices.size() - 1; i++)
			{
				// If first consecuitve element is less than second subtract both and add in the sum varibale. 
				if (prices[i] < prices[i + 1])
				{
					sum += prices[i + 1] - prices[i];

				}
			}

			//Finally return the sum.
			return sum;

		}
};