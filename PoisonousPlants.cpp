#include<iostream>
#include<vector>

// not efficient
int poisonousPlants(std::vector<int> plants)
{
	int days = 0;
	while(true)
	{
		int deaths = 0;
		std::vector<int> alive{plants[0]};
		for(int i = 1; i < plants.size(); i++)
		{
			if(plants[i] > plants[i-1])
			{
				deaths++;
			}
			else
			{
				alive.push_back(plants[i]);
			}
		}
		if(deaths == 0)
		{
			break;
		}
		else
		{
			days++;
			plants = alive;
		}
	}
	return days;	
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> pesticideAmount;
	for(int i = 0; i < n; i++)
	{
		int value;
		std::cin >> value;
		pesticideAmount.push_back(value); 
	}
	
	std::cout << "Days:" << poisonousPlants(pesticideAmount);
}
