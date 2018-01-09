//
//
//

#ifndef OL_TILE_H
#define OL_TILE_H

#include <ol/typedefs.h>
#include <ol/events/EventTarget.h>

#include <string>

namespace ol {

inline std::string to_string(TileCoord const &c)
{
	return std::to_string(std::get<0>(c)) + "," + std::to_string(std::get<1>(c)) + "," + std::to_string(std::get<2>(c));
}

struct TileState {
	enum enum_t {
		IDLE = 0,
		LOADING = 1,
		LOADED = 2,
		ERROR = 3,
		EMPTY = 4,
		ABORT = 5,
	};
};

//goog.provide('ol.Tile');
//
//goog.require('ol');
//goog.require('ol.TileState');
//goog.require('ol.easing');
//goog.require('ol.events.EventTarget');
//goog.require('ol.events.EventType');
//
class OLQT_EXPORT Tile : public ol::events::EventTarget {
private:
	TileState::enum_t m_state;
	ol::TileCoord m_tileCoord;
	int m_transition;
	std::string m_key;

public:
	Tile();
	/**
	 * @classdesc
	 * Base class for tiles.
	 *
	 * @constructor
	 * @abstract
	 * @extends {ol.events.EventTarget}
	 * @param {ol.TileCoord} tileCoord Tile coordinate.
	 * @param {ol.TileState} state State.
	 * @param {olx.TileOptions=} opt_options Tile options.
	 */
	Tile(ol::TileCoord coord, TileState::enum_t state, int transition = 250);
	~Tile();

public:
	/**
	 * @protected
	 */
	void changed();
	/**
	 * @return {string} Key.
	 */
	virtual std::string getKey();
	/**
	 * Get the interim tile most suitable for rendering using the chain of interim
	 * tiles. This corresponds to the  most recent tile that has been loaded, if no
	 * such tile exists, the original tile is returned.
	 * @return {!ol.Tile} Best tile for rendering.
	 */
	virtual ol::Tile *getInterimTile();
	/**
	 * Goes through the chain of interim tiles and discards sections of the chain
	 * that are no longer relevant.
	 */
	virtual void refreshInterimChain();
	/**
	 * Get the tile coordinate for this tile.
	 * @return {ol.TileCoord} The tile coordinate.
	 * @api
	 */
	virtual ol::TileCoord getTileCoord() const;
	/**
	 * @return {ol.TileState} State.
	 */
	virtual ol::TileState::enum_t getState() const;
	/**
	 * @param {ol.TileState} state State.
	 */
	virtual void setState(ol::TileState::enum_t state);
	/**
	 * Load the image or retry if loading previously failed.
	 * Loading is taken care of by the tile queue, and calling this method is
	 * only needed for preloading or for reloading in case of an error.
	 * @abstract
	 * @api
	 */
	virtual void load();
	/**
	 * Get the alpha value for rendering.
	 * @param {number} id An id for the renderer.
	 * @param {number} time The render frame time.
	 * @return {number} A number between 0 and 1.
	 */
	virtual double getAlpha(int id, int tmo);
	/**
	 * Determine if a tile is in an alpha transition.  A tile is considered in
	 * transition if tile.getAlpha() has not yet been called or has been called
	 * and returned 1.
	 * @param {number} id An id for the renderer.
	 * @return {boolean} The tile is in transition.
	 */
	virtual bool inTransition(int id);
	/**
	 * Mark a transition as complete.
	 * @param {number} id An id for the renderer.
	 */
	virtual void endTransition(int id);
};

} // namespace

#endif
