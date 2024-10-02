;;; This program allows the user to set or modify integers and
;;; and examine the results in decimal format

;;;   Programmer:  Henry Walker, Grinnell College
;;;   Written in Scheme by Henry Walker (January 30, 2005)
;;;   Last revised by Henry Walker (January 30, 2005)

(define writeln
;;  print the values on a list, separated by spaces, with a newline at the end
   (lambda ls
      (do ((lst ls (cdr lst)))
          ((null? lst) (newline))
          (display (car lst))
          (display " ")
      )
   )
)

(define printmenu
  (lambda ()
      (writeln)
      (writeln "Menu Options")
      (writeln "  I - initialize each number to a value you have entered")
      (writeln "  A - add 1 to each integer")
      (writeln "  S - subtract 1 from each number")
      (writeln "  M - multiple each number by 2")
      (writeln "  D - divide each number by 2")
      (writeln "  Q - Quit")
      (display "Enter option:  ")
   )
)

(define find-binary-list
   (lambda (inte)
      (letrec ((kernel 
                (lambda (int)
                  (cond ((= int 1) '(#\1))
                        ((odd? (modulo int 2)) 
                            (cons #\1 (kernel (quotient int 2))))
                        (else (cons #\0 (kernel (quotient int 2))))
                  )
                 )
                )
               )
        (list->string
         (cond ((zero? inte) '(#\0))
               ((< inte 0)  
                   (append '( #\- #\space) (reverse (kernel (- inte)))))
               (else (append '( #\+ #\space) (reverse (kernel inte))))
         )
        )
      )
   )
)

(define main
   (lambda ()
      (let ((inte 1))
        (writeln)
        (writeln "This program allows experimentation with different sizes of integers")
        (newline)(newline)
        (writeln "   Initial integer value:  " inte)
            (printmenu)
        (do ((option (read) (read)))
            ((or (equal? option 'q) (equal? option 'Q))
             (writeln "Program terminated"))
            (cond ((or (equal? option 'i) (equal? option 'I)) 
                       (display "   Enter value new integer value:  ")
                       (set! inte (read)))
                  ((or (equal? option 'a) (equal? option 'A)) 
                   (set! inte (+ inte 1)))
                  ((or (equal? option 's) (equal? option 'S)) 
                   (set! inte (- inte 1)))
                  ((or (equal? option 'm) (equal? option 'M)) 
                   (set! inte (* inte 2)))
                  ((or (equal? option 'd) (equal? option 'D)) 
                   (set! inte (quotient inte 2)))
                  (else (writeln "Unrecognized option -- please try again")))
            (writeln "   Resulting integer value")
            (writeln "         (decimal): "  inte)
            (writeln "    (binary sign/magnitude): " (find-binary-list inte))
            (printmenu)
         )
      )
   )
)

(main)

(exit)
