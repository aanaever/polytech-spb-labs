module Group_Process
   use Environment
   use Group_IO

   implicit none
   
contains
   pure subroutine Sort_class_list(Group)
      type(student), intent(inout)  :: Group(:)
      integer        :: min, i
      type(student)  :: tmp_stud
      
      do i = 1, Size(Group)
         min = Minloc(Group(i:)%Birth, 1) + i - 1
          if(Group(i)%Birth > Group(min)%Birth) then
               tmp_stud = Group(i)
               Group(i) = Group(min)
               Group(min) = tmp_stud
            end if
         end do
     

   end subroutine Sort_class_list
 
end module Group_process
