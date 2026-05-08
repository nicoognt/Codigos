(define mascorta (lambda (lista1 lista2)
                   (if (equal? (length lista1) (length lista2))
                       lista1
                       (if (< (length lista1) (length lista2))
                           lista1
                           lista2
                           ))))

(mascorta '(a b) '(c d e))
(mascorta '(a b) '(c d))
(mascorta '(a b) '(c))