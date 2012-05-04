
(defrule CGPA
	=>
	(printout t "your CGPA" crlf)
(bind ?response (read))
	(assert (CGPA ?response))
	)

(defrule cdcs
	=>
	(printout t "have you completed cdcs?(yes/no)" crlf)
(bind ?response (read))
	(assert (cdc ?response)))



(defrule projects
	=>
	(printout t "no. of projects" crlf)
(bind ?response (read))
	(assert (project ?response)))

(defrule electives
	=>
	(printout t "What electives have u done ?" crlf)
	(printout t "1.Algorithms" crlf)
	(printout t "2.Computer graphics" crlf)
	(printout t "3.Artificial Intelligence" crlf)
	(printout t "4.multimedia computing" crlf)
	(printout t "5.Parallel computing" crlf)
	(printout t "6.oopd" crlf)
	(printout t "7.data mining" crlf)
	(printout t "8.fuzzy logic" crlf)
	(printout t "9.adv. operating systems" crlf)
	(printout t "10.image processing" crlf)
	(printout t "answer here(in order) => ")

	(bind ?response (read))
	(assert (elective1 ?response))
(bind ?response (read))
	(assert (elective2 ?response))
(bind ?response (read))
	(assert (elective3 ?response)))



(defrule income
	=>
	(printout t "expected annual income in denominations of Rs.10lakh till 100 lakh" crlf)
(bind ?response (read))
	(assert (aincome ?response)))



(defrule microsoft
	( and ?cg <- (CGPA 6|7|8|9|10) 
		?c <- (cdc yes)
		?p <- (project 1|2|3|4|5|6)
		?el <- (elective1 1|3)
		?el2 <- (elective2 3|5|6)
		?el3 <- (elective3 5|6|9)
		?in <-(aincome 10|20|30|40|50|60)
			
	)
	=>
	(assert (e true))
	(printout t "eligible for company Microsoft" crlf)
	
)

(defrule facebook
 (declare (salience 100))
	( and ?cg <- (CGPA 7|8|9|10) 
		?c <- (cdc yes)
		?p <- (project 4|5|6)
		?el <- (elective1 1)
		?el2 <- (elective2 3|5)
		?el3 <- (elective3 5|7|8)
		?in <-(aincome 10|20|30|40|50|60|70|80)
			
	)
	=>
	(assert (e true))
	(printout t "eligible for company Facebook" crlf)
	
)

(defrule google
 (declare (salience 50))
	( and ?cg <- (CGPA 8|9|10) 
		?c <- (cdc yes)
		?p <- (project 3|4|5|6)
		?el <- (elective1 1|3)
		?el2 <- (elective2 3|5)
		?el3 <- (elective3 5|7)
		?in <-(aincome 10|20|30|40)
			
	)
	=>
	(assert (e true))
	(printout t "eligible for company google" crlf)
	
)

(defrule dreamworks
	( and ?cg <- (CGPA 9|10) 
		?c <- (cdc yes)
		?p <- (project 5|6)
		?el <- (elective1 2|3)
		?el2 <- (elective2 3|4)
		?el3 <- (elective3 4|7|10)
		?in <-(aincome 10|20|30|40|50)
			
	)
	=>
	(assert (e true))
	(printout t "eligible for company Dreamworks" crlf)
	
)

(defrule apple
	( and ?cg <- (CGPA 5|6|7|8|9|10) 
		?c <- (cdc yes)
		?p <- (project 2|3|4|5|6)
		?el <- (elective1 1|2)
		?el2 <- (elective2 2|4|6)
		?el3 <- (elective3 4|6|8|10)
		?in <-(aincome 10|20|30|40|50|60|70|80|90|100)
			
	)
	=>
	(assert (e true))
	(printout t "eligible for company Apple" crlf)
	
)

(defrule nasa
	( and ?cg <- (CGPA 9|10) 
		?c <- (cdc yes)
		?p <- (project 5|6)
		?el <- (elective1 1|2|3)
		?el2 <- (elective2 2|3|5)
		?el3 <- (elective3 3|5|8|10)
		?in <-(aincome 10|20|30|40|50|60)
			
	)
	=>
	(assert (e true))
	(printout t "eligible for company NASA" crlf)
	
)

(defrule not_eligible
 (declare (salience -100))
	(not (e ?))
	
	    
	=>
	(printout t "not eligible for any company" crlf))




	
