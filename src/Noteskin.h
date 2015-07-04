#ifndef NOTESKIN_H_
#define NOTESKIN_H_

class ScreenGameplay7K;
class LuaManager;

class Noteskin
{
	static shared_ptr<LuaManager> NoteskinLua;
	static ScreenGameplay7K* Parent;
	static double NoteScreenSize;
public:
	static void SetupNoteskin(bool SpecialStyle, int Lanes, ScreenGameplay7K *Parent);
	static void Update(float Delta, float CurrentBeat);

	static void DrawNote(VSRG::TrackNote &T, int Lane, float Location);
	static void DrawHoldBody(int Lane, float Location, float Size, int ActiveLevel);
	static float GetBarlineWidth();
	static double GetBarlineStartX();
	static double GetBarlineOffset();
	static bool IsBarlineEnabled();
	static double GetJudgmentY();
	static void DrawHoldHead(VSRG::TrackNote& T, int Lane, float Location);
	static void DrawHoldTail(VSRG::TrackNote& T, int Lane, float Location);
	static double GetNoteOffset();
};

#endif