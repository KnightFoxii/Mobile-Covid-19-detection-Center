<?php

//session_start();
//header('location:login.php');
// Create connection
$conn = mysqli_connect("localhost","id14067095_noob1","%d>S/b24ndK{+@dX","id14067095_esp8266");

if ($conn) {
   // echo "success";
} else {
    # code...
}
mysqli_select_db($conn,'id14067095_esp8266');

$fname = $_POST['firstname'];
$lname = $_POST['lastname'];
$email = $_POST['email'];
$add = $_POST['address'];
$phone = $_POST['phone'];
 
   $sql = "INSERT INTO Registration(fname,lname,address,email,phoneno) values('$fname','$lname','$add','$email','$phone')";
if(mysqli_query($conn, $sql)){
   // echo "Records inserted successfully.";
	header('Location: monitor.php');
} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($conn);
}
   
  

?>