!
! simple subroutine to compute factorial
!
subroutine facto(n, answer)
    integer :: n, i
    double precision :: answer
 
    answer = 1
    do i = 2,n
        answer = answer * i
    end do
end subroutine

