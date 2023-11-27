#include<iostream>
using namespace std;

string items_name(int i);
int items_quantity(int i);
int items_price(int i);

int main()
{
	int main_choice,item_index[10],product_count = 0, product_ava_array[10], item_quantity[10], item_prices[10], item_input_count,purchsae_selection[10],purchase_qunatity;
	char stop;
	string item_name[10];
	do
	{
		char item_count_choice,add_more_item_choice{};
		//Base item Adding
		if (product_count == 0)
		{
			cout << "Do you want to add items (Y/N)";
			cin >> item_count_choice;
			do {
				if (item_count_choice == 'Y' || item_count_choice == 'y')
				{

					cout << "How many Items do you want to add?";
					cin >> item_input_count;
					if (item_input_count <= 10)
					{
						for (int i = 1; i <= item_input_count; i++)
						{
							item_name[i] = items_name(i);
							item_quantity[i] = items_quantity(i);
							item_prices[i] = items_price(i);
							item_index[i] = i;
							if (item_quantity[i] != 0)
							{
								product_ava_array[i] = 1;
							}
						}
							product_count+=item_input_count;
						
					}
					else
						cout << "Max items to input are 10."<<endl;
				}
				else
					cout << "There are no items to be purchased. Add some!" << endl;
				
				cout << "Do you want to add items? (Y/N)";
				cin >> item_count_choice;
				
					//Menu
					for (int i = 1; i <= item_input_count; i++)
					{
						if (product_ava_array[i] == 1)
						{
							cout << i << ". " << item_name[i] << ":  " << item_prices[i] << endl;
						}
					}

					//Purchase
					do {

						cout << "Enter the number to purchase that item: ";
						cin >> main_choice;
						if (main_choice == 101)
						{
							cout << "How many Items do you want to add?";
							cin >> item_input_count;
							if (item_input_count <= 10)
							{
								for (int i = 1; i <= item_input_count; i++)
								{
									item_name[i] = items_name(i);
									item_quantity[i] = items_quantity(i);
									item_prices[i] = items_price(i);
									item_index[i] = i;
									if (item_quantity[i] != 0)
									{
										product_ava_array[i] = 1;
									}
								}
								product_count += item_input_count;

							}
							else
								cout << "Max items to input are 10." << endl;
						}
						else if (main_choice == 1 || main_choice == 2 || main_choice == 3 || main_choice == 4 || main_choice == 5 || main_choice == 6 || main_choice == 7 || main_choice == 8 || main_choice == 9 || main_choice == 10)
						{
							cout << "Quantity: ";
							cin >> purchase_qunatity;
							int count = 0;
							for (int i = 1; i <= item_input_count; i++)
							{
								int j = 1, price_notax, tax;
								if (i == main_choice)
								{
									price_notax = item_prices[i] * purchase_qunatity;
									tax = price_notax * 0.14;
									cout << j << ". " << item_name[i] << ":  " << price_notax + tax;
									j++;
									count++;
									item_quantity[i] = item_quantity[i] - purchase_qunatity;
								}
							}
							if (count == 0)
								cout << "Item not avalible.";
						}
						else
							cout << "Try again!";
					}
					while (main_choice != 420);
			} while (product_count==0); //item_count_choice != 'N' && item_count_choice != 'n'
		}
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
