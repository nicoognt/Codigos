(define subst (lambda (c t lista)
                (if (null? lista)
                    '()
                    (if (equal? (car lista) c)
                        (cons t (subst c t (cdr lista)))
                        (cons (car lista) (subst c t (cdr lista)))))
                ))

(subst 'c 'k '( c o c o n u t))