<?php

	$servername ="127.0.0.1";
	$username ="root";
	$password ="";
	$db="myDB";
	$sql = "CREATE DATABASE IF NOT EXISTS myDB";

    include'Donnees.inc.php';


	$conn = mysqli_connect($servername, $username, $password);
// Check connection

if (!$conn) {
    die(" Echec connection : " . mysqli_connect_error());

}

// creation base de données

$sql = "CREATE DATABASE IF NOT EXISTS myDB";
if(mysqli_query($conn,$sql))
{
	echo '<p class="erreur" >'."myDB cree/presente ".'</p>';
} else {
	echo '<p class="erreur" >'."erreur creation database" . mysqli_error($conn) .'</p>';
}

$conn = mysqli_connect($servername, $username, $password,$db);


//===============
//
// Creation table recette + gestion erreur
//
//===============

$sql ="CREATE TABLE RECETTE(
idRecette VARCHAR(30) PRIMARY KEY,
ingredients VARCHAR(250) NOT NULL,
preparation VARCHAR(1000) NOT NULL
)
";
if (mysqli_query($conn, $sql)) {
    echo '<p class="erreur" >'." TABLE RECETTE cree ".'</p>' ;
} else {
    echo '<p class="erreur" >'."Erreur creation RECETTE: " . mysqli_error($conn).'</p>';
}

//===============
//
// Creation table Contient + gestion erreur
//
//===============

$sql="CREATE TABLE CONTIENT(
idAliment VARCHAR(40) PRIMARY KEY,
idRecette VARCHAR(30) REFERENCES RECETTE(idRecette)
)
";
if (mysqli_query($conn, $sql)) {
    echo '<p class="erreur" >'."TABLE CONTIENT cree".'</p>';
} else {
    echo '<p class="erreur">'."Erreur creation CONTIENT: " . mysqli_error($conn).'</p>';
}

//===============
//
// Creation table Aliment + gestion erreur
//
//===============

$sql="CREATE TABLE ALIMENT(
idALiment VARCHAR(40) REFERENCES CONTIENT(idAliment)
)";

if (mysqli_query($conn, $sql)) {
    echo '<p class="erreur" >'."TABLE ALIMENT cree".'</p>';
} else {
    echo '<p class="erreur">'."Erreur creation ALIMENT: " . mysqli_error($conn).'</p>';
}

//===============
//
// Creation table ESTFILS + gestion erreur
//
//===============

$sql="CREATE TABLE ESTFILS(
idAliment VARCHAR(40),
SuperCat VARCHAR(40),
CONSTRAINT alim_a_pour_pere PRIMARY KEY(idAliment, SuperCat)
)
";

if (mysqli_query($conn, $sql)) {
    echo '<p class="erreur" >'."TABLE ESTFILS cree".'</p>';
} else {
    echo '<p class="erreur">'."Erreur creation ESTFILS: " . mysqli_error($conn).'</p>';
}

//===============
//
// Creation table ESTPERE + gestion erreur
//
//===============

$sql="CREATE TABLE ESTPERE(
idAliment VARCHAR(40),
SousCat VARCHAR(40),
CONSTRAINT alim_a_pour_fils PRIMARY KEY(idAliment, SousCat)
)
";

if (mysqli_query($conn, $sql)) {
    echo '<p class="erreur" >'."TABLE ESTFILS cree".'</p>';
} else {
    echo '<p class="erreur">'."Erreur creation ESTFILS: " . mysqli_error($conn).'</p>';
}

//on parcourt $hierarchie ( le tableau d'aliment)
foreach($Hierarchie as $nom =>$description_categorie){
    $nomalim=$nom;
    echo $nomalim;
    

    // on recupère le tableau qui decrit les categories de l'aliment
    $tab_description_categorie=array($description_categorie);
    foreach($tab_description_categorie as $tab)
       {
        // on parcourt les deux sous tableaux de categories
        foreach($tab as $x )
           { 
            foreach($x as $info)
                {   //if(strcmp($x,'sous-categorie')==0)
                   //{ 
                    echo $info;}
                   //}

            }
        echo '<p class="erreur">'.'</p>';
       } 
   /* foreach($nom as $tab_description_categorie=>$contenu)
    {
        echo $typecategorie;
    }*/
}


/*
$sql="DROP DATABASE myDB";
mysqli_query($conn,$sql);*/

mysqli_close($conn);
	
?>