module Source_IO
   use Environment

   implicit none
   integer, parameter                  :: SURNAME_LEN = 15 
   
   type Student
      character(SURNAME_LEN, CH_)      :: Surname = ""
      type(Student), pointer           :: Next  => Null()
   end type Student

contains
   function Read_Student(InputFile) result (Stud)
      type(Student), pointer     :: Stud
      character(*), intent(in)   :: InputFile
      integer                    :: In

      open (file=InputFile, encoding=E_, newunit=In)
         Stud => Read_Student_Line(in)
      close (In)
   end function Read_Student


recursive function Read_Student_Line(in) result(Stud)
   type(Student), pointer :: Stud
   integer, intent(in)    :: In
   integer                :: IO

   allocate(Stud)
   read(In, '(a)', iostat = IO) Stud%Surname
   call Handle_IO_Status(IO, "reading line from source code")
   if(IO == 0) then
      Stud%Next => Read_Student_Line(In)
   else
      Stud => Null()
   end if
   end function Read_Student_Line



   subroutine Output_Student(OutputFile, Stud, List_Name, Position)
      character(*), intent(in)      :: OutputFile, List_Name, Position
      type(Student), intent(in)     :: Stud
      integer                       :: Out

      open (file=OutputFile, encoding=E_, position=Position, newunit=Out)
         write (out, '(/a)') List_Name
         call Output_Student_Line(Out, Stud)
      close (Out)
   end subroutine Output_Student


   recursive subroutine Output_Student_Line(Out, Stud)
      integer, intent(in)       :: Out
      type(Student), intent(in) :: Stud
      integer                   :: IO

      write (Out, '(a)', iostat=IO) Stud%Surname
      call Handle_IO_Status(IO, "writing line to file")
      if(Associated(Stud%next)) &
         call Output_Student_Line(Out, Stud%next)
      end subroutine Output_Student_Line
end module Source_IO 
