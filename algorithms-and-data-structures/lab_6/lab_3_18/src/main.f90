program lab_3_18
   use Environment
   use Source_Process
   use Source_IO

   implicit none
   character(:), allocatable :: F1, F2
   integer(I_)               :: Amount = 0
character(2), parameter             :: str = "wi"
   type(Student), pointer :: Stud  => Null()
   type(Student), pointer :: Sorted => Null()

   F1 = "../data/input.txt"
   F2 = "output.txt"
   
   Stud => Read_Student(F1)
   if (Associated(Stud)) then
      call Get_List(Stud, Amount)
      call Output_Student(F2, Stud, "Исходный список:", "rewind")

   end if
  
   

  Sorted => Sort_list(Stud)
call Output_Student(F2, Sorted, "sdd", "append")

end program lab_3_18
