<?php

$value = $_POST['value'];		//Get the value
$unit = $_POST['unit'];			//Get the id if the unit where we want to update the value
$column = $_POST['column'];	

//connect to the database
include("database_connect.php");

// Check the connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}


mysqli_query($con,"UPDATE ESPtable2 SET $column = '{$value}'
WHERE id=$unit");

//go back to the interface
header("location: monitor.php");
?>