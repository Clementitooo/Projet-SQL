
--- Général --- Version: 2.0 (2024-01-11) 

Ce fichier README a été généré le [2023-22-12] par [CLEMENT BARJOLLE].

Dernière mise-à-jour le : [2024-01-1].

# INFORMATIONS GENERALES
Le programme que vous vous apprêtez a utiliser comporte une instance de connexion puis de communication avec une base de donnée,
ce programme à était réaliser lors d'un projet MySQL durant une formation de BTS Système Numérique (2ème année).

## MySQL APP : Version 2.0 (Inclusion d'une interface de connexion)
 
## Adresse de contact : clementbarjolle1@gmail.com
 


# INFORMATIONS METHODOLOGIQUES
Tout d'abord, lors de la compilation du programme, renseignez l'utilisateur et le mot de passe de votre DB, ensuite rajoutez l'adresse DNS sur laquel est situer votre DB.
Compléter également le nom puis lancer la connexion, en cas d'erreur, vérifiez vos identifiants.

Une fois le programme démarrer, vous êtes libres d'utiliser le logiciel de communication SQL.



## Conditions environnementales / experimentales : 
L'utilisation de l'application nécessite obligatoirement une base de donnée en fonction et accessible.



## Description des sources et méthodes utilisées pour collecter et générer les données :
L'application va ce servir de votre base de donnée pour afficher la totalitée des tables qu'elle contient, ensuite plusieurs options seront possible pour naviguer dans
votre base de donnée, a savoir que le mode en autonomie nécessite les connaissances nécessaires en SQL pour effectuer une requête.



## Méthodes de traitement des données :
Les données ne sortent pas du programme, sauf diffusion de votre écran vous manipulerez en toute sécuritée votre base de donnée.



## Arborescence/plan de classement des fichiers :
Le logiciel contient deux classes principales : 

Mainwindow.h -> Ce fichier coordonne les deux autres tout en ajoutant des déclarations pour la classe
Mainwindow.cpp -> C'est ici que le logiciel contient toutes ses fonctionnalités
Mainwindow.ui -> C'est ici que l'interface du logiciel est générée

PopUp.h -> ""
PopUp.cpp -> C'est ici que l'interface de connexion récolte vos données pour les vérifiers
PopUp.ui -> "" l'interface de connexion est générée



## Informations additionnelles : 
Liste des registres du programme (fonctionnalitées possibles)

Register N°11 -> Ligne count			 (calcul le total de ligne de votre table)
Register N°12 -> Describe			 (Décrit chaque colonne de votre programme)
Register N°13 -> Select			 (Affiche le contenu de votre table)

Register N°21 -> Add Column			 (Ajoute une colonne a la table selectionner)
Register N°22 -> Drop Table			 (Supprime une table de votre DB)
Register N°23 -> Drop Column			 (Supprime une colonne de votre DB)

Register N°31 -> Developper Mod			 (Autonomie sur l'utilisation du logiciel)



#[!}DISCLAIMER : 
Dû a un enchaînement de modifications, une ligne de code à était involontairement supprimer créant ainsi un bug de génération des requêtes, lorsque vous 
faites une requête et changez de table, vous ne pouvez pas réenvoyez directement la requête, vous devez reselectionner la requête à effectuer pour palier le bug,
par manque de temps celui-ci n'a pas pu être fix.

Le bouton save n'a pas pu être finit par manque de temps également..
