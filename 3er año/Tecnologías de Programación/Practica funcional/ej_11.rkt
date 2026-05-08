(define pred (lambda (num1 num2)
               (if (equal? num1 num2)
                   #t
                   #f
                   )))


(define contador_apariciones (lambda (num lista)
                              (if (null? lista)
                                   0
                              (if (equal? num (car lista))
                                   (+ 1 (contador_apariciones num (cdr lista)))
                                   (contador_apariciones num (cdr lista))
                                   ))))
  

(contador_apariciones 3 '(1 2 3 4 5 4 3 2 1))