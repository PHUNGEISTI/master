// Essai.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <mpi.h>
#include <vector>
#include <tuple>

using namespace std;
int main()
{
	//Achat : id,nb achat,Max € a payer
	vector<tuple<int, int, int> > vente;
	vente.push_back(make_tuple(1, 10, 20));
	vente.push_back(make_tuple(2, 2, 5));
	vente.push_back(make_tuple(3, 6, 7));
	vente.push_back(make_tuple(4, 12, 13));
	vente.push_back(make_tuple(5, 14, 25));

	//Achat : id,nb vente,min € vente
	vector<tuple<int, int, int> > achat;
	achat.push_back(make_tuple(6, 12, 4));
	achat.push_back(make_tuple(7, 4, 5));
	achat.push_back(make_tuple(8, 8, 7));
	
	int nb_VenteTot = 0;
	int nb_AchatTot = 0;
	for (int i = 0;i < vente.size();i++) {
		nb_VenteTot += get<1>(vente[i]);
	}


	for (int i = 0;i < achat.size();i++) {
		nb_AchatTot += get<1>(achat[i]);
	}

	cout<<"Vente ! " << nb_VenteTot<<"\n";
	double rs_Achat,rs_Vente ;


	if (nb_VenteTot < nb_AchatTot)
		rs_Achat = (double)nb_VenteTot / nb_AchatTot;
	else
		rs_Achat =1.0;


	if (nb_VenteTot> nb_AchatTot)
		rs_Vente = (double)nb_AchatTot/ nb_VenteTot;
	else 
		rs_Vente = 1.0;


	vector<tuple<int, int> > repartition_achat,repartition_vente;


	for (int i = 0;i < achat.size();i++) {
		double tmp = (double)get<1>(achat[i]) * rs_Achat;
		repartition_achat.push_back(make_tuple(get<0>(achat[i]),round(tmp) ));
	}



	for (int i = 0;i < vente.size();i++) {
		double tmp = (double)get<1>(vente[i]) * rs_Vente;
		cout << "tmp: " << tmp << "\n";
		repartition_vente.push_back(make_tuple(get<0>(vente[i]), round(tmp)));
	}
	for (int i = 0;i < repartition_achat.size();i++) {
		cout << "îd: " << get<0>(repartition_achat[i]) << " nb Achat tot : " << get<1>(repartition_achat[i]) << "\n";
	}


	for (int i = 0;i < repartition_vente.size();i++) {
		cout << "îd: " << get<0>(repartition_vente[i]) << " nb Vente tot : " << get<1>(repartition_vente[i]) << "\n";
	}


	int a = round(11.75);

	system("pause");

    return 0;
}

