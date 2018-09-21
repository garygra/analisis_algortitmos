#! /usr/bin/sbcl --script
; (format t "Hello, world!")
; (format t "~&~S~&" (cdr sb-ext:*posix-argv*))


(defun factorial (N)
  ; "Compute the factorial of N."
  (if (= N 1)
      1
    (* N (factorial (- N 1)))))

(defun log_2(x)
	(/ (log x) (log 2))
	)

(defun f4(n)
	(log_2 (factorial n)) 
	)

(defun f4_aux (n)
	(let ((sum_var 0) (n_aux 0) )
	; (defvar sum_var 0)
	; (defvar n_aux 1)
	; (print sum_var)
		; (dotimes (n_aux n sum_var) 
		; 	(+ sum_var (log_2 (setq n_aux (+ n_aux 1))))
		; 	; (+ n_aux 1)
		; 	; (format t "~d " x)
		; )
		; (print n)
		(loop for n_aux from 1 to n
   			do 
   				(setq sum_var (+ sum_var (log_2 n_aux)))

   				
		)
		sum_var
		; (print sum_var)
	; (loop
   		
 ;   		(when (= n_aux n) (return sum_var))
 ;   	)
 		; sum_var
	)
	; (if (= N 1)
		; 1
		; (+ (log_2 n) (log_2 (f4_aux (- n 1 ) )))
		; )
	)

(defun fa(n)
	(factorial (floor (log_2 n)))
	)

(defun fb(n)
	(log_2 (log_2 n))
	)


; (print (parse-integer (car (cdr sb-ext:*posix-argv*))))
; (print (factorial (parse-integer (car (cdr sb-ext:*posix-argv*)))))
(defvar n_in)
(defvar func)
(setq n_in (parse-integer (car (cdr sb-ext:*posix-argv*))))
(setq func (parse-integer (car (cddr sb-ext:*posix-argv*))))

; (format t "~d~C~d~C~C" n_in #\tab (f4_aux n_in) #\return #\linefeed)


; (print func)
; (format t "~d~C~d~C~d~C~d~C~d~C~C" n_in
; 				 #\tab
; 				 (f4 n_in) 
; 				 #\tab
; 				 (factorial n_in)
; 				 #\tab
; 				 (fa n_in)
; 				 #\tab
; 				 (fb n_in) 
; 				 #\return #\linefeed)

(cond ((= func 1) (format t "~d~C~d~C~C" n_in #\tab (f4_aux n_in) #\return #\linefeed))
	  ((= func 2) (format t "~d~C~d~C~C" n_in #\tab (factorial n_in) #\return #\linefeed))
	  ((= func 3) (format t "~d~C~d~C~C" n_in #\tab (fa n_in) #\return #\linefeed))
	  ((= func 4) (format t "~d~C~d~C~C" n_in #\tab (fb n_in) #\return #\linefeed))
   (t (format t "ERROR " a)))