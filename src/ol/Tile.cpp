//
//
//

#include <ol/Tile.h>

ol::Tile::Tile() : m_tileCoord(),m_state(),m_transition(250)
{
}

ol::Tile::Tile(ol::TileCoord coord, TileState::enum_t state, int transition)
	: m_tileCoord(coord), m_state(state), m_transition(transition)
{
	//ol.Tile = function(tileCoord, state, opt_options) {
	//  ol.events.EventTarget.call(this);
	//
	//  var options = opt_options ? opt_options : {};
	//
	//  /**
	//   * @type {ol.TileCoord}
	//   */
	//  this.tileCoord = tileCoord;
	//
	//  /**
	//   * @protected
	//   * @type {ol.TileState}
	//   */
	//  this.state = state;
	//
	//  /**
	//   * An "interim" tile for this tile. The interim tile may be used while this
	//   * one is loading, for "smooth" transitions when changing params/dimensions
	//   * on the source.
	//   * @type {ol.Tile}
	//   */
	//  this.interimTile = null;
	//
	//  /**
	//   * A key assigned to the tile. This is used by the tile source to determine
	//   * if this tile can effectively be used, or if a new tile should be created
	//   * and this one be used as an interim tile for this new tile.
	//   * @type {string}
	//   */
	//  this.key = '';
	//
	//  /**
	//   * The duration for the opacity transition.
	//   * @type {number}
	//   */
	//  this.transition_ = options.transition === undefined ?
	//    250 : options.transition;
	//
	//  /**
	//   * Lookup of start times for rendering transitions.  If the start time is
	//   * equal to -1, the transition is complete.
	//   * @type {Object.<number, number>}
	//   */
	//  this.transitionStarts_ = {};
	//
	//};
	//ol.inherits(ol.Tile, ol.events.EventTarget);
	//
	//
}

ol::Tile::~Tile()
{

}

void ol::Tile::changed()
{
	//ol.Tile.prototype.changed = function() {
	//  this.dispatchEvent(ol.events.EventType.CHANGE);
	//};
	// TODO: implement
}

std::string ol::Tile::getKey()
{
	//ol.Tile.prototype.getKey = function() {
	//  return this.key + '/' + this.tileCoord;
	//};
	return m_key + "/" + ol::to_string(m_tileCoord);
}

ol::Tile * ol::Tile::getInterimTile()
{
	//ol.Tile.prototype.getInterimTile = function() {
	//  if (!this.interimTile) {
	//    //empty chain
	//    return this;
	//  }
	//  var tile = this.interimTile;
	//
	//  // find the first loaded tile and return it. Since the chain is sorted in
	//  // decreasing order of creation time, there is no need to search the remainder
	//  // of the list (all those tiles correspond to older requests and will be
	//  // cleaned up by refreshInterimChain)
	//  do {
	//    if (tile.getState() == ol.TileState.LOADED) {
	//      return tile;
	//    }
	//    tile = tile.interimTile;
	//  } while (tile);
	//
	//  // we can not find a better tile
	//  return this;
	//};
	// TODO: implement

	return this;
}

void ol::Tile::refreshInterimChain()
{
	//ol.Tile.prototype.refreshInterimChain = function() {
	//  if (!this.interimTile) {
	//    return;
	//  }
	//
	//  var tile = this.interimTile;
	//  var prev = this;
	//
	//  do {
	//    if (tile.getState() == ol.TileState.LOADED) {
	//      //we have a loaded tile, we can discard the rest of the list
	//      //we would could abort any LOADING tile request
	//      //older than this tile (i.e. any LOADING tile following this entry in the chain)
	//      tile.interimTile = null;
	//      break;
	//    } else if (tile.getState() == ol.TileState.LOADING) {
	//      //keep this LOADING tile any loaded tiles later in the chain are
	//      //older than this tile, so we're still interested in the request
	//      prev = tile;
	//    } else if (tile.getState() == ol.TileState.IDLE) {
	//      //the head of the list is the most current tile, we don't need
	//      //to start any other requests for this chain
	//      prev.interimTile = tile.interimTile;
	//    } else {
	//      prev = tile;
	//    }
	//    tile = prev.interimTile;
	//  } while (tile);
	//};

	// TODO: implement
}

ol::TileCoord ol::Tile::getTileCoord() const
{
	//ol.Tile.prototype.getTileCoord = function() {
	//  return this.tileCoord;
	//};
	return m_tileCoord;
}

ol::TileState::enum_t ol::Tile::getState() const
{
	//ol.Tile.prototype.getState = function() {
	//  return this.state;
	//};
	return m_state;
}

void ol::Tile::setState(ol::TileState::enum_t state)
{
	//ol.Tile.prototype.setState = function(state) {
	//  this.state = state;
	//  this.changed();
	//};
	m_state = state;
	changed();
}

void ol::Tile::load()
{
	//ol.Tile.prototype.load = function() {};
}

double ol::Tile::getAlpha(int id, int tmo)
{
	//ol.Tile.prototype.getAlpha = function(id, time) {
	//  if (!this.transition_) {
	//    return 1;
	//  }
	//
	//  var start = this.transitionStarts_[id];
	//  if (!start) {
	//    start = time;
	//    this.transitionStarts_[id] = start;
	//  } else if (start === -1) {
	//    return 1;
	//  }
	//
	//  var delta = time - start + (1000 / 60); // avoid rendering at 0
	//  if (delta >= this.transition_) {
	//    return 1;
	//  }
	//  return ol.easing.easeIn(delta / this.transition_);
	//};

	return 1; // TODO: implement
}

bool ol::Tile::inTransition(int id)
{
	//ol.Tile.prototype.inTransition = function(id) {
	//  if (!this.transition_) {
	//    return false;
	//  }
	//  return this.transitionStarts_[id] !== -1;
	//};
	return false; //
}

void ol::Tile::endTransition(int id)
{
	//ol.Tile.prototype.endTransition = function(id) {
	//  if (this.transition_) {
	//    this.transitionStarts_[id] = -1;
	//  }
}
