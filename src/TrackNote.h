

#ifndef TAPNOTE_H_
#define TAPNOTE_H_
#include "Song.h"

namespace VSRG
{
	const unsigned char EnabledFlag = 1 << 0;
	const unsigned char WasHitFlag = 1 << 1;
	const unsigned char HeadEnabledFlag = 1 << 2;
	const unsigned char FailedHitFlag = 1 << 3;
	const unsigned char InvisibleFlag = 1 << 4;

	// REMEMBER WE MUST BE 8-BYTE ALIGNED. It's either 16, 24 or 32...
	// note data: 28 bytes
	// Going to be 32 bytes on its own with alignment...
	struct NoteData
	{
		// start time and end time are 8 bytes each - 16 bytes.
		double StartTime, EndTime;
		uint32 Sound; // Do we really need more than this?
		uint8 NoteKind; // To be used with ENoteKind.

		NoteData() {
			StartTime = EndTime = 0;
			Sound = 0;
			NoteKind = NK_NORMAL;
		}
	};

	class TrackNote : public TimeBased<TrackNote, double>
	{
	private:
		// 16 bytes (Implied 8 with inherited TimeBased)
		double EndTime;

		// 8 bytes
		float b_pos;
		float b_pos_holdend;

		// 2 bytes
		uint16 Sound; 

		// 3 bytes
		uint8 NoteKind; // To be used with ENoteKind.
		uint8 FractionKind;
		uint8 EnabledHitFlags;
		
		// 32 bytes aligned
	public:
		TrackNote();

		// Build this tracknote from this NoteData.
		void AssignNotedata(const NoteData &Data);
		
		// Get the start time.
		double &GetDataStartTime();

		// Get the actual end time regardless of start time.
		double &GetDataEndTime();

		// Get what sound this note has. (Redundant)
		uint16 &GetDataSound();

		// Get the kind of head this note has.
		uint8  GetDataNoteKind();

		// Get what fraction of a beat this note belongs to.
		uint8  GetDataFractionKind();

		// Set this note's position on the vertical track.
		void AssignPosition(float Position, float endPosition = 0);

		// Assign a fraction of a beat to this note.
		void AssignFraction(double frc); // frc = fraction of a beat

		// Mark this note/hold head as hit.
		void Hit();

		// Add this much drift to the note.
		void AddTime(double Time);

		// Disable note for judgment completely.
		void Disable();

		// Disable the head of this note. Leaves the option of hitting the tail if not disabled.
		void DisableHead();

		// Get the position on the track of the note/hold head.
		float GetVertical() const;

		// Get the position on the track of the hold's tail.
		float GetVerticalHold() const;

		// Get whether this note is a hold.
		bool IsHold() const;

		// Get whether this note can be judged.
		bool IsEnabled() const;

		// Get whether the head of this note (if a hold) is enabled.
		bool IsHeadEnabled() const;

		// Get whether this note was hit on the head.
		bool WasNoteHit() const;

		// Get whether this note is a judgable kind of note. Doesn't depend on failure state.
		bool IsJudgable() const;

		// Get whether this note should be drawn - independant of whether it was hit.
		bool IsVisible() const;

		// Get the sound associated to this note.
		int GetSound() const;
		
		// Get the maximum between the start and end times. If not a hold, Start = End.
		double GetTimeFinal() const;

		// Get the start time of this note. If not a hold, Start = End.
		double GetStartTime() const;

		// Get the beat fraction kind.
		int GetFracKind() const;

		~TrackNote();

		// Get the size of this hold on the unmodified track.
		float GetHoldSize() const;

		// Get the position of the tail of this hold on the unmodified track.
		float GetHoldEndVertical();

		// Informative flags. For use in mechanics.
		// Mark this object as failed. Used only to have the additional failed state.
		void FailHit();

		// Get whether this object was marked as failed.
		bool FailedHit() const;

		// Make this note invisible - That is to say, make no attempt at drawing it.
		void MakeInvisible();
	};

}
#endif
