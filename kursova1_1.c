#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int* pstorage_cells=&storage_cells[0][0];
	entering_of_products(pstorage_cells);
	system("pause");
}

int entering_of_products(int* pstorage_cells){
	int quantity_of_storage=0, quantity=0;
	int i;
	int i3, j3;
	double weight[X*Y];
	for(i=0; i<(Y*X); i++)
	{
	printf("Enter Name: ");
	char name[15];
	scanf("%s\n", &name);

	printf("Enter Type: (Drink, Fruit, Fastfood)");
	char type[15];
	scanf("%s\n", &type);

	printf("Enter Weight: ");
	scanf("%lf\n", &weight[i]);
	double *pweight=&weight[0];

	printf("Enter Price: ");
	double price[X*Y];
	scanf("%lf\n", &price[i]);
	double *pprice=&price[0];

	//entering_of_qunatity(i, quantity_of_storage);
	entering_of_qunatity(&quantity_of_storage, &quantity);
	
     
    if (strcmp(type, "drink")==0)//popylvane v tochno opredelena kletka napravi
    {
    	if((quantity==Z*2)||(quantity==Z*3)||(quantity==Z*4)||(quantity==Z*5)||(quantity==Z*6)||(quantity==Z*7)||(quantity==Z*8)||(quantity==Z*9))
    	{
    		do
    		{
    			for (i3 = 0; i < X*Y; ++i3)
    			{
    					if ((quantity/Z)==((*pstorage_cells)+i3))
    					{
    						*(pstorage_cells+i3)=0;
    					}
    					else
    					{
    						*(pstorage_cells+i3)=0;
    					}
    			}
    		} while (i3=X*Y);
    		/*do{
    			for (int i2 = 0; i < X*Y; ++i2)
    			{
    				for (int j2 = 0; i < X*Y; ++j2)
    				{
    					if ((quantity/Z)==matrix[i2][j2])//opravi matrix kym pointera za cell
    					{
    						matrix[i2][j2]=0;
    					}
    					else
    					{
    						matrix[i2][j2]=0;
    					}
    				}
    			}
    		}whlie(i2*j2!=X*Y);*/
        }
    }
	if (quantity_of_storage>H)
	{
	 	i+=30;
	}
	}
	for (int i3 = 0, ca=1; i < X*Y; ++i3, ++ca)
	{
		if(weight[i3]>weight[i3+ca])
		{
			//int temp
		}
	}
}

int entering_of_qunatity(int i, int quantity_of_storage){
	printf("Enter Quantity: ");
	int quantity[X*Y];
	scanf("%d\n", &quantity[i]);
	int* pquantity=&quantity[i];
	i++;
	 //int *pquantity=&quantity[0];

	if((quantity[i]!=0)&&(quantity[i]>0))
	{
		if (quantity[i]<=Z)//zapylvane na raftovete samo s edin vid product
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
	  		if (quantity[i]<100)//za poveche ot 100?
	  		{
	  			if((quantity[i]==Z*2)||(quantity[i]==Z*3)||(quantity[i]==Z*4)||(quantity[i]==Z*5)||(quantity[i]==Z*6)||(quantity[i]==Z*7)||(quantity[i]==Z*8)||(quantity[i]==Z*9)){
	  				quantity_of_storage+=(quantity[i]/Z)*Z;
	  					if (quantity_of_storage>H)
	  			 			{
	  		 					int difference=quantity_of_storage-H;
	 	 						quantity_of_storage-=H;
	 	 	 					printf("Cappacity of the machine is used,\n %d piece/s of the last item is/are removed \n", difference);
	 	        			}
	  			}
	  			else if((quantity[i]!=Z*2)&&(quantity[i]!=Z*3)&&(quantity[i]!=Z*4)&&(quantity[i]!=Z*5)&&(quantity[i]!=Z*6)&&(quantity[i]!=Z*7)&&(quantity[i]!=Z*8)&&(quantity[i]!=Z*9))
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
