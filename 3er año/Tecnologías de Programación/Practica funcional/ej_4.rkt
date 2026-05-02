; consigna: extraer la x de las listas siguientes
(define L1 '( a b c . x))
( cdr ( cdr ( cdr L1)))

(define L2 '(a b c x))
(car (cdr (cdr (cdr L2))))

(define L3 '((a . x) b))
(cdr (car L3))

(define L4 '(x . a))
(car L4)

(define L5 '(a . x))
(cdr L5)