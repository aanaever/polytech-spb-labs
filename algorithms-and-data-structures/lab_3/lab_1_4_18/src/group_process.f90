module Group_Process
   use Environment
   use Group_IO

   implicit none

contains
   pure subroutine Sort_class_list(Group, N)
      type(student), intent(inout)  :: Group(:)
      integer, intent(in)           :: N

      call Drop_down(Group, 1, N)
   end subroutine Sort_class_list
  
   pure recursive subroutine Drop_down(Group,i, N)
      type(student), intent(inout)  :: Group(:)
      integer, intent(in)           ::  N, i
      integer                       :: min
      type(student)  :: tmp_stud
      
      min = Minloc(Group(i:)%Birth, 1) + i - 1

      if (Group(i)%Birth > Group(min)%Birth) then
         tmp_stud = Group(i)
         Group(i) = Group(min)
         Group(min) = tmp_stud
      end if
      if (i < N) &
         call Drop_down(Group, i+1, N)
   end subroutine Drop_down
 
end module group_process
