#pragma once

class VisibleGameObject
{
public:

	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);
	virtual void Update(float elapsedTime);
	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded() const;

	int getId(){
		return id;
	}
	void setId(int id){
		this->id = id;
	}



protected:
	sf::Sprite& GetSprite();

private:

	int id;

	sf::Sprite  _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;



};
