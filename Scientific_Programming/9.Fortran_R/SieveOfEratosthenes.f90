subroutine SieveOfEratosthenes(n, nprimes)
  
  implicit none

  integer, intent(in) :: n
  integer, intent(out) :: nprimes

  integer :: imax, neff, counter=1
  integer, allocatable :: prime(:)
  integer :: i,p

  if ( mod(n,2) .eq. 0) then
     imax=n/2
  else
     imax=(n+1)/2
  end if

  neff= 2*(imax-1)+1
  allocate(prime(0:imax))
 
  do i=0, imax
     prime(i)=1
  end do

  write(*,*) " Dimension of array: ", imax
  write(*,*) " Array with indices between 0 to ", imax-1
  write(*,'(1X,A,I0,A,A)') " Stores primality of odd numbers in range [1,", neff, "]", char(0)

  ! The loop runs over all odd numbers starting at 3
  do p = 3, n/2+1, 2
     ! If prime(p) is 1, then it is a prime
     if(prime((p-1)/2) == 1) then
        ! Update all multiples of p
        do i = p*2, neff, p
           if (mod(i,2)/=0) then 
              prime((i-1)/2) = 0
           end if
        end do
     end if
  end do
  
! Print all prime numbers if the number is small otherwise just count the number of primes found
  if (n <= 10000) then
     write(*,'(I10)', advance="no") 2
     ! Starting with index 1 instead of zero because (2*0)+1 = 1 is not prime
     do i = 1, imax, 1
        if(prime(i) == 1) then
           write(*,'(I10)', advance="no") 2*i+1
           counter = counter + 1
        end if
        if (counter == 15) then
           write(*,*) char(0)
           counter=0
        end if
     end do
     write(*,*) char(0)
  end if
     
  do i = 1, imax, 1
     if(prime(i) == 1) then
        nprimes = nprimes + 1
     end if
  end do

end subroutine SieveOfEratosthenes


program main

  implicit none

  integer :: n=1, nprimes=0, count, stat
  character(len=32) :: arg

  count = command_argument_count()
!  print *, count

  if (count > 0) then
     CALL get_command_argument(1, arg)
     read(arg,*,iostat=stat)  n
  else 
     n = 100
  end if

  write(*,*) char(0)
  write(*,*) " Prime numbers up to ", n
  call SieveOfEratosthenes(n, nprimes)
  write(*,*) " Total number of primes found: ", nprimes

end program main
