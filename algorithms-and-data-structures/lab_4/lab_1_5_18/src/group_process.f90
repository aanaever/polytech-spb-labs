module Group_Process
   use Environment
   use Group_IO

   implicit none

contains
   pure recursive subroutine Get_list_by_gender(Stud, List, Amount, Genders)
      type(student), intent(in)        :: Stud
      type(student), pointer           :: List
      integer(I_), intent(inout)       :: Amount
      character(kind=CH_), intent(in)  :: Genders
     
      if (Stud%Gender == Genders) then
         allocate (List, source=Stud)
         Amount = Amount + 1
         List%next => Null()
         if (Associated(Stud%next)) &
            call Get_list_by_gender(Stud%next, List%next, Amount, Genders)
      else if (Associated(Stud%next)) then
         call Get_list_by_gender(Stud%next, List, Amount, Genders)
      end if

   end subroutine Get_list_by_gender
 
   pure recursive subroutine SelectionSort(ClassList)
      type(student), pointer, intent(inout)  :: ClassList 

      if(Associated(ClassList)) then
         call ChooseAndPaste(ClassList, ClassList, ClassList%next) 
         call SelectionSort(ClassList%next)
      end if
   end subroutine SelectionSort

   pure recursive subroutine ChooseAndPaste(ClassList, min, current)
      type(student), pointer  :: ClassList
      type(student), pointer  :: min
      type(student), pointer  :: current 
      type(student), pointer  :: tmp_stud

      if(Associated(current)) then
         if(current%Birth < min%Birth) then 
            call ChooseAndPaste(ClassList, current, current%next) 
         else 
            call ChooseAndPaste(ClassList, min, current%next) 
         end if
      else 
         if(.not. Associated(ClassList, min)) then 
        tmp_stud => ClassList
        ClassList => min
        min => tmp_stud
      end if
   end if
   end subroutine ChooseAndPaste

end module Group_process
