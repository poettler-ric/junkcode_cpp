program out
  use iso_fortran_env
  implicit none

  real :: defreal
  real(kind=real32) :: r32
  real(kind=real64) :: r64
  real(kind=real128) :: r128

  double precision :: defdouble

  integer :: defint
  integer :: fdump
  integer(kind = 2) :: i2
  integer(kind = 4) :: i4
  integer(kind = 8) :: i8
  integer(kind = int8) :: ik8
  integer(kind = int16) :: ik16
  integer(kind = int32) :: ik32
  integer(kind = int64) :: ik64

  character(len=40) :: string

  logical :: b
  logical :: exists

  defreal = 3.141593
  print *, defreal
  r32 = 3.141593
  print *, r32
  r64 = 3.141593
  print *, r64
  r128 = 3.141593
  print *, r128

  defdouble = 3.141593
  print *, defdouble

  print *, huge(defint)
  print *, huge(i2)
  print *, huge(i4)
  print *, huge(i8)
  print *, huge(ik8)
  print *, huge(ik16)
  print *, huge(ik32)
  print *, huge(ik64)

  string = "richi"
  print *, string

  b = .true.
  print *, b

  inquire(file="fdump", exist=exists)
  if (exists) then
    open(newunit=fdump, file="fdump", status="replace", access="stream", action="write")
  else
    open(newunit=fdump, file="fdump", status="new", access="stream", action="write")
  endif
  write(fdump) huge(defint)
  write(fdump) defreal
  write(fdump) defdouble
  close(fdump)

end program
