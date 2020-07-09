-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 14, 2020 at 06:20 AM
-- Server version: 10.3.16-MariaDB
-- PHP Version: 7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `id14067095_esp8266`
--

-- --------------------------------------------------------

--
-- Table structure for table `ESPtable2`
--

CREATE TABLE `ESPtable2` (
  `id` int(5) NOT NULL,
  `PASSWORD` int(5) NOT NULL,
  `SENT_NUMBER_1` int(5) NOT NULL,
  `SENT_NUMBER_2` int(5) NOT NULL,
  `SENT_NUMBER_3` int(5) NOT NULL,
  `SENT_NUMBER_4` int(5) NOT NULL,
  `SENT_BOOL_1` tinyint(1) NOT NULL,
  `SENT_BOOL_2` tinyint(1) NOT NULL,
  `SENT_BOOL_3` tinyint(1) NOT NULL,
  `RECEIVED_BOOL1` int(1) NOT NULL,
  `RECEIVED_BOOL2` int(1) NOT NULL,
  `RECEIVED_BOOL3` int(1) NOT NULL,
  `RECEIVED_BOOL4` int(1) NOT NULL,
  `RECEIVED_BOOL5` int(1) NOT NULL,
  `RECEIVED_NUM1` int(5) NOT NULL,
  `RECEIVED_NUM2` int(5) NOT NULL,
  `RECEIVED_NUM3` int(5) NOT NULL,
  `RECEIVED_NUM4` int(5) NOT NULL,
  `RECEIVED_NUM5` int(5) NOT NULL,
  `TEXT_1` text CHARACTER SET latin1 COLLATE latin1_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ESPtable2`
--

INSERT INTO `ESPtable2` (`id`, `PASSWORD`, `SENT_NUMBER_1`, `SENT_NUMBER_2`, `SENT_NUMBER_3`, `SENT_NUMBER_4`, `SENT_BOOL_1`, `SENT_BOOL_2`, `SENT_BOOL_3`, `RECEIVED_BOOL1`, `RECEIVED_BOOL2`, `RECEIVED_BOOL3`, `RECEIVED_BOOL4`, `RECEIVED_BOOL5`, `RECEIVED_NUM1`, `RECEIVED_NUM2`, `RECEIVED_NUM3`, `RECEIVED_NUM4`, `RECEIVED_NUM5`, `TEXT_1`) VALUES
(99999, 12345, 100, 97, 90, 1313, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Nebune!');

-- --------------------------------------------------------

--
-- Table structure for table `Registration`
--

CREATE TABLE `Registration` (
  `fname` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `lname` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `address` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `email` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `phoneno` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `Registration`
--

INSERT INTO `Registration` (`fname`, `lname`, `address`, `email`, `phoneno`) VALUES
('Hrushikesh', 'Bhamre', 'Kothrud , pune', 'bhamrehrushikesh78@gmail.com', '9552535014'),
('Hrushikesh', 'Bhamre', 'Kothrud , pune', 'bhamrehrushikesh78@gmail.com', '9552535014'),
('Hrushikesh', 'Bhamre', 'Kothrud , pune', 'bhamrehrushikesh78@gmail.com', '9552535014');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `ESPtable2`
--
ALTER TABLE `ESPtable2`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `ESPtable2`
--
ALTER TABLE `ESPtable2`
  MODIFY `id` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=100000;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
