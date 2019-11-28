#include <stdio.h>
#include <stdlib.h>

#define X 5 //koloni
#define Y 6 //redove---ako se uvelichi trqbvat oshte if-ove za papylvane namtricata
#define Z 10 //mqsto za producti
#define H X*Y*Z //obshto mqsto za producti

//kak da napravq cikyl vyvejdasht razlichni dumi v edin string bez zadadena stoinost za elementi na stringa
int entering_of_products();
int entering_of_qunatity();

int main()
{
	printf("Enter products info\n\tName, Type, Weight, Price, Quantity\n");
	//entering_of_products();
	int storage_cells[Y][X];
	int cell=1;
	for (int i = 0; i < Y; ++i)//i igrae rolqta na kolona---popylvane na kletkite v tablica
	{
		for (int j = 0; i < X; ++j)
		{
			storage_cells[i][j]=cell;
			cell++;
		}
	}
	entering_of_products(cell);
	system("pause");
}

int entering_of_products(int cell){
	int quantity_of_storage=0;
	for(int i=0; i<(Y*X); i++)
	{
	printf("Enter Name: ");
	char name[15]=scanf("%s\n");
	scanf("%s\n", &name);

	printf("Enter Type: (Drink, Fruit, Fastfood)");
	char type[15];
	scanf("%s\n", &type);

	printf("Enter Weight: ");
	double weight[X*Y];
	scanf("%lf\n", &weight[i]);
	double *pweight=&weight[0];

	printf("Enter Price: ");
	double price[X*Y];
	scanf("%lf\n", &price[i]);
	double *pprice=&price[0];

	entering_of_qunatity(i, quantity_of_storage);
	quantity_of_storage=entering_of_qunatity(quantity_of_storage);
	quantity=entering_of_qunatity(quantity[i])
     
    switch type{
		case "drink": 
	}

	if (quantity_of_storage>H)
	{
	 	i+=30;
	}
	}
}

int entering_of_qunatity(int i, int quantity_of_storage){
	printf("Enter Quantity: ");
	int quantity[X*Y];
	scanf("%d\n", &quantity[i]);
	i++;
	 //int *pquantity=&quantity[0];

	if((quantity[i]!=0)&&(quantity[i]>0))
	{
		if (quantity[i]<Z)//zapylvane na raftovete samo s edin vid product
		{
	 		quantity_of_storage+=Z;
	 		if (quantity_of_storage>H)
	 		{
	 	 		quantity_of_storage-=Z;
	 	 		printf("Cappacity of the machine is used,\n 10 pieces of the last item are removed\n");
	 		}
	    }
	    else if (quantity[i]>Z)
	    {
	  		if (quantity[i]<100)
	  		{
	  			quantity_of_storage+=((quantity[i]/Z)+1)*Z;
	  			if (quantity_of_storage>H)
	  			{
	  		 		int difference=quantity_of_storage-H;
	 	 			quantity_of_storage-=H;
	 	 	 		printf("Cappacity of the machine is used,\n %d piece/s of the last item is/are removed \n", difference);
	 	        }
	  	    }
	    }
	}
	else
	{
		system("cls");
	 	printf("Enter positive quantity\n");
	 	i--;
	 	entering_of_qunatity(i, quantity_of_storage);
	}
	return quantity_of_storage, quantity[i];
}
