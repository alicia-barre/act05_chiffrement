// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{


	std::string monMessageHash = "Super message superchouette";



	HashGestion LM;
	std::cout << LM.CalculateSHA256(monMessageHash) << std::endl;

	AesGestion monAES;
	monAES.GenerateAESKey();
	monAES.SaveAESKeyToFile("ma_clef_aes.key");
	monAES.LoadAESKeyFromFile("ma_clef_aes.key");
	monAES.EncryptFileAES256("ma_clef_aes.key", "ma_clef_aes_crypt.key");
	monAES.DecryptFileAES256("ma_clef_aes_crypt.key", "ma_clef_aes_decrypt.key");

	RsaGestion monRSA;
	//monRSA.generationClef("clef_public_alicia.key", "clef_prive_alicia.key", 2048);
	monRSA.chargementClefs("clef_public_alicia.key", "clef_prive_alicia.key");

	monRSA.chiffreDansFichier("salut", "fichier_chiffre_rsa_alicia.crypt");
	monRSA.dechiffrementFichier("fichier_chiffre_rsa_alicia.crypt", "fichier_dechiffre_rsa_alicia.decrypt", true);
	std::string message = "hello";
	std::string MessageCrypt = monRSA.chiffrementRsa(message);
	std::cout << MessageCrypt << std::endl;
	std::string MessageDecrypt = monRSA.dechiffrementRsa(MessageCrypt);
	std::cout << MessageDecrypt << std::endl;



}


