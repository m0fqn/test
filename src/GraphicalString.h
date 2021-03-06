#ifndef GGString_H_
#define GGString_H_

class Font;

class GraphicalString : public Sprite
{
	GString mText;
	Font* mFont;
public:
	GraphicalString();
	void SetText(GString _Text);
	GString GetText() const;
	void SetFont(Font* _Font);
	Font* GetFont() const;

	void Render() override;
};

#endif
