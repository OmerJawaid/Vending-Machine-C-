#include<iostream>
using namespace std;

string items_name(int i);
int items_quantity(int i);
int items_price(int i);

int main()
{
	int main_choice,item_index[10],item_count = 0, item_quantity[10], item_prices[10];
	char stop;
	string item_name[10];
	do
	{
		char item_count_choice,add_more_item_choice{};
		//Base item Adding
		if (item_count == 0)
		{
			cout << "Do you want to add items (Y/N)";
			cin >> item_count_choice;
			do {
				if (item_count_choice == 'Y'|| item_count_choice == 'y')
				{	
					int item_input_count;
					cout << "How many Items do you want to add?";
					cin >> item_input_count;
					if (item_input_count <= 6)
					{
						switch (item_input_count)
						{
						case 1:
							item_name[1] = items_name(1);
							item_quantity[1] = items_quantity(1);
							item_prices[1] = items_price(1);
							item_index[1]=1;
							item_count += 1;
							break;
						case 2:
							for (int i = 1; i <= 2; i++)
							{
								item_name[i] = items_name(i);
								item_quantity[i] = items_quantity(i);
								item_prices[i] = items_price(i);
								item_index[i] = i;
							}
							item_count += 2;
							break;
						case 3:
							for (int i = 1; i <= 3; i++)
							{
								item_name[i] = items_name(i);
								item_quantity[i] = items_quantity(i);
								item_prices[i] = items_price(i);
								item_index[i] = i;
							}
							item_count += 3;
							break;
						case 4:
							for (int i = 1; i <= 4; i++)
							{
								item_name[i] = items_name(i);
								item_quantity[i] = items_quantity(i);
								item_prices[i] = items_price(i);
								item_index[i] = i;
							}
							item_count += 4;
							break;
						case 5:
							for (int i = 1; i <= 5; i++)
							{
								item_name[i] = items_name(i);
								item_quantity[i] = items_quantity(i);
								item_prices[i] = items_price(i);
								item_index[i] = i;
							}
							item_count += 5;
							break;
						case 6:
							for (int i = 1; i <= 6; i++)
							{
								item_name[i] = items_name(i);
								item_quantity[i] = items_quantity(i);
								item_prices[i] = items_price(i);
								item_index[i] = i;
							}
							item_count += 6;
							break;
						}
					}
					else
						cout << "Max items to input are 6."<<endl;
				}
				else
					cout << "There are no items to be purchased. Add some!" << endl;
				cout << "Do you want to add more items? (Y/N)";
				cin >> add_more_item_choice;
			} while (add_more_item_choice != 'N' && add_more_item_choice != 'n');
		}

		//Menu
		cout << "1. Restocking" << endl
			<< "2. Purchase" << endl
			<< "What do you want to do?";
		cin >> main_choice;
		//Restocking
		if (main_choice == 1)
		{
			int item_search,adding_quantity;
			cout << "Which Item you want to restock?\nEnter the index"<<endl;
				cin >> item_search;
				for (int i = 1; i <= 6; i++)
				{
					if (item_search == i)
					{
						cout << item_name[i] <<" " << item_quantity[i] << endl;
						cout << "Enter the quantity to add: ";
						cin >> adding_quantity;
						item_quantity[i] += adding_quantity;
						cout << "New Quantity: " << item_quantity[i]<<endl
							<<"Item Restocked"<<endl;
						break;
					}
				}
		}
		//Purchasing
		else if (main_choice == 2)
		{
			int item_search, price_notax, tax_price,price_tax;
			cout << "Enter the index of item you want to purchase: ";
			cin >> item_search;
			for (int i = 1; i <= 6; i++)
			{
				if (item_search == i)
				{
					cout << item_name[i] << " "<<item_quantity[i]<<endl;
					if (item_quantity == 0)
					{
						cout << "The product is not in stock"<<endl;
						break;
					}
					price_notax = item_quantity[i] * item_prices[i];
					tax_price = price_notax * 0.14;
					price_tax = price_notax - tax_price;
					item_quantity[i]--;
					cout << "Price: " << price_tax;
					cout << "Item Purchased Successfully."<<endl;
					break;
				}
			}
		}
		else
			cout << "Enter correct choice.";

		cout << "If you want to quit press Q else press any alphabet.";
		cin >> stop;
	} while (stop != 'Q' && stop != 'q');
}
string items_name(int i)
{
	string item_name[10];
		cout << "Enter the item name: ";
	cin >> item_name[i];
	return item_name[i];
}
int items_quantity(int i)
{
	int item_quantity[10];
	cout << "Enter the item quantity: ";
	cin >> item_quantity[i];
	return item_quantity[i];
}
int items_price(int i)
{
	int item_price[10];
	cout << "Enter the item price: ";
	cin >> item_price[i];
	return item_price[i];
}