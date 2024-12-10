program lab_1_2
   use Environment

   implicit none
   integer, parameter               :: STUD_AMOUNT = 5, SURNAME_LEN = 15, INITIALS_LEN = 5, MARKS_AMOUNT = 4
   character(kind=CH_), parameter   :: MALE = Char(1052, CH_), FEMALE = Char(1046, CH_)
   character(:), allocatable        :: input_file, output_file

   character(kind=CH_)  :: Surnames(STUD_AMOUNT, SURNAME_LEN)  = "", &
                           Initials(STUD_AMOUNT, INITIALS_LEN) = "", &
                           Genders(STUD_AMOUNT)                   = ""
   character(kind=CH_), allocatable :: Boys_Surnames(:, :), Girls_Surnames(:, :)
   character(kind=CH_), allocatable :: Boys_Initials(:, :), Girls_Initials(:, :)
   integer              :: Marks(STUD_AMOUNT) = 0, i = 0
   integer, allocatable :: Boys_Marks(:), Girls_Marks(:)
   input_file  = "../data/class.txt"
   output_file = "output.txt"
   
   call Read_class_list(input_file, Surnames, Initials, Genders, Marks)

   call Output_class_list(output_file, Surnames, Initials, Genders, Marks, &
      "Исходный список:", "rewind")
      
   call Get_list_by_gender(Surnames, Initials, Genders, Marks, Boys_Surnames, &
      Boys_Initials, Boys_Marks, MALE)
   call Get_list_by_gender(Surnames, Initials, Genders, Marks, Girls_Surnames, &
      Girls_Initials, Girls_Marks, FEMALE)

   call Sort_class_list(Boys_Marks)
   call Sort_class_list(Girls_Marks)

   call Output_class_list(output_file, Boys_Surnames, Boys_Initials, [(MALE, i = 1, Size(Boys_Marks))], &
      Boys_Marks, "Успеваемость юношей:", "append")
   call Output_class_list(output_file, Girls_Surnames, Girls_Initials, [(FEMALE, i = 1, Size(Girls_Marks))], &
      Girls_Marks, "Успеваемость девушек:", "append")
contains
   subroutine Read_class_list(Input_File, Surnames, Initials, Genders, Marks)
      character(*)         Input_File
      character(kind=CH_)  Surnames(:, :), Initials(:, :), Genders(:)
      integer              Marks(:)
      intent (in)          Input_File
      intent (out)         Surnames, Initials, Genders, Marks

      integer In, IO, i
      character(:), allocatable  :: format
      
      open (file=Input_File, encoding=E_, newunit=In)
         format = '(' // SURNAME_LEN // 'a1, 1x, ' // INITIALS_LEN // 'a1, 1x, a, 1x, i4)'
         read (In, format, iostat=IO) (Surnames(i, :), Initials(i, :), Genders(i), Marks(i), &
            i = 1, STUD_AMOUNT)
         call Handle_IO_status(IO, "reading class list")
      close (In)
   end subroutine Read_class_list

   subroutine Output_class_list(Output_File, Surnames, Initials, Genders, Marks, List_name, Position)
      character(*)         Output_File, Position, List_name
      character(kind=CH_)  Surnames(:, :), Initials(:, :), Genders(:)
      integer              Marks(:)
      intent (in)          Output_File, Surnames, Initials, Genders, Marks, List_name, Position

      integer                    :: Out, i, IO
      character(:), allocatable  :: format
   
      open (file=output_file, encoding=E_, position=position, newunit=Out)
         write (out, '(/a)') List_name
         format = '(' // SURNAME_LEN // 'a1, 1x, ' // INITIALS_LEN // 'a1, 1x, a, 1x, i4)'
         write (Out, format, iostat=IO) &
            (Surnames(i, :), Initials(i, :), Genders(i), Marks(i), i = 1, Size(Marks))
         call Handle_IO_status(IO, "writing " // List_name)
      close (Out)
   end subroutine Output_class_list

   pure subroutine Get_list_by_gender(Surnames, Initials, Genders, Marks, &
         Gender_Surnames, Gender_Initials, Gender_Marks, Gender)
      character(kind=CH_)  Surnames(:, :), Initials(:, :), Genders(:)
      integer              Marks(:)
      character(kind=CH_)  Gender_Surnames(:, :), Gender_Initials(:, :)
      integer              Gender_Marks(:)
      character(kind=CH_)  Gender
      intent(in)           Surnames, Initials, Genders, Marks, Gender
      intent(out)          Gender_Surnames, Gender_Initials, Gender_Marks
      allocatable          Gender_Surnames, Gender_Initials, Gender_Marks

      logical, allocatable :: Is_A_Gender(:)
      integer, allocatable :: Gender_Pos(:)
      integer              :: Gender_Amount, i
      integer, parameter   :: INDEXES(*) = [(i, i = 1, STUD_AMOUNT)]

      Is_A_Gender    = Genders == Gender
      Gender_Amount  = Count(Is_A_Gender)

      Gender_Pos  = Pack(INDEXES, Is_A_Gender)
      allocate (Gender_Surnames(Gender_Amount, SURNAME_LEN), &
         Gender_Initials(Gender_Amount, INITIALS_LEN), Gender_Marks(Gender_Amount))
     
      do concurrent (i = 1:Gender_Amount)
         Gender_Surnames(i, :)  = Surnames(Gender_Pos(i), :)
         Gender_Initials(i, :)  = Initials(Gender_Pos(i), :)
         Gender_Marks(i)  = Marks(Gender_Pos(i))
      end do

 
   end subroutine Get_list_by_gender

   pure subroutine Sort_class_list(Marks)
      integer              Marks(:)
      intent (inout)       Marks

      integer              i, temp, min

      do i = 1, Size(Marks)
         min = Minloc(Marks(i:), 1) + i - 1
         if(Marks(i) > Marks(min)) then
            temp = Marks(i)
            Marks(i) = Marks(min)
            Marks(min) = temp
         end if
      end do
      end subroutine Sort_class_list

   end program lab_1_2
