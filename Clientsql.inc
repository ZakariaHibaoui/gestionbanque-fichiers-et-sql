<?php


require_once("connexion.inc") ;


//Q 1

     
 function  existeClient($cin)
 {    
   global $connect;
    
   $sql = "SELECT cin FROM client WHERE cin = $cin ";

   $resultat=$connect->query($sql);     // on a exec  qui  execute la commande sql mais sauf query permet te retourne les resultats surtout quand tu affiche les tableaux
   
   $basedonne = $resultat->fetchAll();     //fetchAll retourne les valeurs et on utilise car on a utilise PDO
 
   foreach($basedonne as $ligne) 

   if($ligne["cin"]==$cin)
   {
   echo "votre compte existe"."<br>";
   
   return 1;
   }
 
   return 0; 
   
   
 }

 


//Q 4

 function nouveauClient($nom,$prenom,$address,$numero,$montant,$cin)
 {
             if(!existeClient($cin))
    {

     global $connect;
    
     $sql = "INSERT INTO client(nom, prenom, addresse ,cin) VALUES (\"$nom\",\"$prenom\",\"$address\",\"$cin\")";

     $connect->exec($sql); // on a exec  qui  execute la commande sql mais sauf query permet te retourne les resultats surtout quand tu affiche les tableaux
    

    nouveauCompte($numero,$montant,$cin);
    

    }




 
//Q 6

function infos($cin)
{

   global $connect;
    
    $sql = "SELECT nom ,prenom,numero,montant FROM client INNER JOIN compte ON client.cin = compte.cin where client.cin = $cin";
    
     $resultat=$connect->query($sql);
   
    $basedonne = $resultat->fetchAll();
 
  foreach($basedonne as $ligne)
 
  echo $ligne["nom"]." ".$ligne["prenom"]." ".$ligne["numero"]." "."<br>".$ligne["montant"];  //    . pour les liaisons  ""  cad espace ebtre les variables
    

 
}

//Q 7
function supprime($cin)
{
      if( existeClient($cin) )

      {  
              global $connect;
                
              $sql = "SELECT * FROM client INNER JOIN compte ON client.cin = compte.cin;DELETE FROM client WHERE cin = $cin;";

               $connect->exec($sql);
    
      }
}



?>