(define agrupar (lambda (lista1)
                  (if (null? lista1)
                      '()
                      (cons (filter (lambda (x) (equal? x (car lista1))) lista1)
                            (agrupar (filter (lambda (x) (not (equal? x (car lista1)))) lista1))
                            ))))

