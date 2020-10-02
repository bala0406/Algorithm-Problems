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

//The below method is the efficient one which of O(n)
class Plant
{
public:
    int value;
    int days;

    Plant(int value, int days)
    {
        this->value = value;
        this->days = days;
    }
};

int poisonousPlants(vector<int> plants) {

   int maxDays = 0;
    std::stack<Plant> stack;
    for (int plant : plants)
    {
        int daysAlive = 0;
        while (!stack.empty() && plant <= stack.top().value)
        {
            int days = stack.top().days;
            stack.pop();
            daysAlive = std::max(daysAlive, days);
        }

        if (stack.empty())
        {
            daysAlive = 0;
        }
        else
        {
            daysAlive++;
        }
        maxDays = std::max(daysAlive, maxDays);
        stack.push(Plant(plant, daysAlive));
    }
    return maxDays;  
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
