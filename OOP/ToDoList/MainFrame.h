#pragma once
#include <wx/wx.h>
#include <ctime>
#include <string>
#include <wx/notebook.h>



class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void CreateControls();
	void BindEventHandlers();
	void AddSavedTasks();


	void OnAddButtonClicked(wxCommandEvent& evt);
	void OnInputEnter(wxCommandEvent& evt);
	void OnListKeyDown(wxKeyEvent& evt);
	void OnClearButtonClicked(wxCommandEvent& evt);
	void OnWindowClosed(wxCloseEvent& evt);

	void OnCheckListBoxToggle(wxCommandEvent& evt);



	void AddTaskFromInput();
	void DeleteSelectedTask();
	void MoveSelectedTask(int offset);
	void SwapTasks(int i, int j);
	

	void UpdateProgressGauge();

	std::string GetCurrentDate() const;

	void OnEditItem(wxCommandEvent& evt);
	
	
	std::ostringstream* ss;

	wxPanel* panel;
	wxStaticText* headlineText;
	wxTextCtrl* inputField;
	wxButton* addButton;
	wxCheckListBox* checkListBox;
	wxButton* clearButton;
	wxButton* editButton;
	wxGauge* progressGauge;
	wxStaticText* progressText;
	wxStaticText* currentDateText;
	


	wxListBox* taskList;

	
};

