(define distance2d (lambda (lista1 lista2)
                     (sqrt (+ (expt (- (car lista2) (car lista1)) 2)
                              (expt (- (cdr lista2) (cdr lista1)) 2)
                              ))))

(distance2d '(1 . 1) '(2 . 2))
                              