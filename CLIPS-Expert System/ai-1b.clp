

(defrule get-details

	=>
	(printout t "Name - ")
	(bind ?response (read))
	
	(assert (name ?response))
	(printout t "Age - ")
	(bind ?response (read))
	(assert (age ?response))
	(printout t "Percentage - ")
	(bind ?response (read))
	(assert (percentage ?response))
	(printout t "Branch - ")
	(bind ?response (read))
	(assert (branch ?response))
	(printout t "Passing out year - ")
	(bind ?response (read))
	(assert (year ?response)))

(defrule test
	=>
	(printout t "BITSAT Score - ")
	(printout t "1.score>320  ")
	(printout t "2.280<score<320  ")
	(printout t "3.250<score<280  ")
	(printout t "4.score<250  ")
	(bind ?response (read))
	(assert (score ?response))

	(printout t "Interested in: - ")
	(printout t "1.Maths  ")
	(printout t "2.Physics  ")
	(printout t "3.Chemistry  ")
	(printout t "4.Biology  ")
	(printout t "5.Economics  ")
	(bind ?response (read))
	(assert (option ?response)))

(defrule maths1
	( and ?s <- (score 1)
	?i <- (option 1)
	)
	=>
	(printout t " CS " crlf))
	
(defrule maths2
	( and ?s <- (score 2|3)
	?i <- (option 1)
	)
	=>
	(printout t " MSc Maths " crlf))

(defrule physics1
	( and ?s <- (score 1)
	?i <- (option 2)
	)
	=>
	(printout t " ECE " crlf))

(defrule physics1
	( and ?s <- (score 2|3)
	?i <- (option 2)
	)
	=>
	(printout t " MSc Physics " crlf))

(defrule chem1
	( and ?s <- (score 1|2)
	?i <- (option 3)
	)
	=>
	(printout t " Chemical " crlf))

(defrule chem1
	( and ?s <- (score 3)
	?i <- (option 3)
	)
	=>
	(printout t " MSc Chemistry " crlf))

(defrule bio
	( and ?s <- (score 1|2|3)
	?i <- (option 4)
	)
	=>
	(printout t " MSc Bio "crlf))

(defrule eco
	( and ?s <- (score 1|2|3)
	?i <- (option 5)
	)
	=>
	(printout t " MSc Economics " crlf))

(defrule not-eligible
(declare (salience -100))
	(not(score 1|2|3))
	=>
	(printout t " not eligible" crlf))