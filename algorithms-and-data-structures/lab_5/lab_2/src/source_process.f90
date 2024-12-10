module Source_Process
  
   use Environment
   use Source_IO

   implicit none

contains
      recursive subroutine List_Mask(Code, Diff)
         type(SourceLine), intent(in) :: Code
         type(SourceLine), pointer    :: Diff
         character(kind = CH_), parameter :: dot ="."
         character(kind = CH_), parameter :: str="wi"    

         if((INDEX(Code%String, str) /= 0) .AND. (INDEX(Code%String, dot)/= 0)) then
            allocate (Diff, source=Code)
            Diff%next => Null()
         if (Associated(Code%next)) &
            call List_Mask(Code%next, Diff%next)
      else if (Associated(Code%next)) then
            call List_Mask(Code%next, Diff)
      else 
      Diff => Null() 
   end if
   end subroutine List_Mask

end module Source_process
