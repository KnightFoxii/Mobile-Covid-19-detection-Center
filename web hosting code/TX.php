<?php

foreach($_REQUEST as $key => $value)  
{

if($key =="id"){
$unit = $value;
}	
if($key =="pw"){
$pass = $value;
}	
if($key =="un"){
$update_number = $value;
}
	
if($update_number == 1)
{
	if($key =="n1"){
		$sent_nr_1 = $value;
	}			
}
else if($update_number == 2)
{
	if($key =="n2"){
	$sent_nr_2 = $value;
	}			
}
else if($update_number == 3)
{
	if($key =="n3"){
	$sent_nr_3 = $value;
	}			
}
else if($update_number == 4)
{
	if($key =="n4"){
	$sent_nr_4 = $value;
	}			
}	
	
else if($update_number == 5)
	{
	if($key =="b6"){
	$sent_bool_1 = $value;
	}	
	if($key =="b7"){
	$sent_bool_2 = $value;
	}	
	if($key =="b8"){
	$sent_bool_3 = $value;
	}	
}
}//End of foreach


include("database_connect.php"); 	

// Check  the connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}


if($update_number == 1)	
	{
		mysqli_query($con,"UPDATE ESPtable2 SET SENT_NUMBER_1 = $sent_nr_1 WHERE id=$unit AND PASSWORD=$pass");	
	}
else if($update_number == 2)	//The same and so on...
	{
		mysqli_query($con,"UPDATE ESPtable2 SET SENT_NUMBER_2 = $sent_nr_2 WHERE id=$unit AND PASSWORD=$pass");	;	
	}
else if($update_number == 3)
	{
		mysqli_query($con,"UPDATE ESPtable2 SET SENT_NUMBER_3 = $sent_nr_3 WHERE id=$unit AND PASSWORD=$pass");	;	
	}
else if($update_number == 4)
	{
		mysqli_query($con,"UPDATE ESPtable2 SET SENT_NUMBER_4 = $sent_nr_4 WHERE id=$unit AND PASSWORD=$pass");	;	
	}

else if($update_number == 5)
	{
		mysqli_query($con,"UPDATE ESPtable2 SET SENT_BOOL_1 = $sent_bool_1, SENT_BOOL_2 = $sent_bool_2, SENT_BOOL_3 = $sent_bool_3 
		WHERE id=$unit AND PASSWORD=$pass");	;	
	}




date_default_timezone_set('UTC');
$t1 = date("gi"); 	//This will return 1:23 as 123


$result = mysqli_query($con,"SELECT * FROM ESPtable2");


while($row = mysqli_fetch_array($result)) {
if($row['id'] == $unit){
	
		
		$b1 = $row['RECEIVED_BOOL1'];	
		$b2 = $row['RECEIVED_BOOL2'];	
		$b3 = $row['RECEIVED_BOOL3'];
		$b4 = $row['RECEIVED_BOOL4'];	
		$b5 = $row['RECEIVED_BOOL5'];
		
		$n1 = $row['RECEIVED_NUM1'];	
		$n2 = $row['RECEIVED_NUM2'];	
		$n3 = $row['RECEIVED_NUM3'];
		$n4 = $row['RECEIVED_NUM4'];	
		$n5 = $row['RECEIVED_NUM5'];
		
		$n6 = $row['TEXT_1'];
		
		
		echo " _t1$t1##_b1$b1##_b2$b2##_b3$b3##_b4$b4##_b5$b5##_n1$n1##_n2$n2##_n3$n3##_n4$n4##_n5$n5##_n6$n6##";
	
}


	
}
?>








