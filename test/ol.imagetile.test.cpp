/*
* Copyright (C) 2018
* All rights reserved.
*
*/

//#include "ol.tilegrid.tilegrid.test.h"

//#include <ol/tilegrid/TileGrid.h>

#include <ol/ImageTile.h>
#include <ol/source/Image.h>
#include <ol/events.h>
#include <ol/events/eventtype.h>

#include "gtest/gtest.h"

//goog.require('ol.ImageTile');
//goog.require('ol.TileState');
//goog.require('ol.events');
//goog.require('ol.events.EventType');
//goog.require('ol.source.Image');
//
//
//describe('ol.ImageTile', function() {

TEST(ol_ImageTile, t1)
{
}
//
//    describe('#load()', function() {
class defaultLoadFunction : public ol::TileLoadFunctionType {
public:
    virtual void operator () (ol::Tile *tile, std::string const &url)
    {
    }
};

TEST(ol_ImageTile, hash_load)
{
    //
    //        it('can load idle tile', function(done) {
    {
        ol::TileCoord tileCoord = { 0, 0, 0 };
        //            var state = ol.TileState.IDLE;
        auto state = ol::TileState::IDLE;
        //            var src = 'spec/ol/data/osm-0-0-0.png';
        std::string src = "spec/ol/data/osm-0-0-0.png";
        ////            var tileLoadFunction = ol.source.Image.defaultImageLoadFunction;
        //auto tileLoadFunction = ol::source::Image::defaultImageLoadFunction;

        //            var tile = new ol.ImageTile(tileCoord, state, src, null, tileLoadFunction);
        ol::ImageTile tile = ol::ImageTile(tileCoord, state, src, std::string(), defaultLoadFunction());
        //
        auto previousState = tile.getState();
        //
        //            ol.events.listen(tile, ol.events.EventType.CHANGE, function(event) {
        ol::events::listen(tile, ol::events::EventType::CHANGE, [](void *that, void *data) {
            //                var state = tile.getState();
            //                if (previousState == ol.TileState.IDLE) {
            //                    expect(state).to.be(ol.TileState.LOADING);
            //                }
            //                else if (previousState == ol.TileState.LOADING) {
            //                    expect(state).to.be(ol.TileState.LOADED);
            //                    done();
            //                }
            //                else {
            //                    expect().fail();
            //                }
            //                previousState = state;
        });

        //tile.load();
    }
    //        });
    //
    //        it('can load error tile', function(done) {
    {
        //            var tileCoord = [0, 0, 0];
        ol::TileCoord tileCoord = { 0, 0, 0 };
        //            var state = ol.TileState.ERROR;
        auto state = ol::TileState::ERROR;
        //            var src = 'spec/ol/data/osm-0-0-0.png';
        std::string src = "spec/ol/data/osm-0-0-0.png";
        //            var tileLoadFunction = ol.source.Image.defaultImageLoadFunction;
        //            var tile = new ol.ImageTile(tileCoord, state, src, null, tileLoadFunction);
        auto tile = ol::ImageTile(tileCoord, state, src, std::string(), defaultLoadFunction());
        //
        auto previousState = tile.getState();
        //
        ol::events::listen(tile, ol::events::EventType::CHANGE, [](void *, void *) {
            //                var state = tile.getState();
            //                if (previousState == ol.TileState.ERROR) {
            //                    expect(state).to.be(ol.TileState.LOADING);
            //                }
            //                else if (previousState == ol.TileState.LOADING) {
            //                    expect(state).to.be(ol.TileState.LOADED);
            //                    done();
            //                }
            //                else {
            //                    expect().fail();
            //                }
            //                previousState = state;
        });
        
        tile.load();
    }
    //        it('loads an empty image on error ', function(done) {
    {
        //            var tileCoord = [0, 0, 0];
        //            var state = ol.TileState.IDLE;
        //            var src = 'spec/ol/data/osm-0-0-99.png';
        //            var tileLoadFunction = ol.source.Image.defaultImageLoadFunction;
        //            var tile = new ol.ImageTile(tileCoord, state, src, null, tileLoadFunction);
        //
        //            var key = ol.events.listen(tile, ol.events.EventType.CHANGE, function(event) {
        //                var state = tile.getState();
        //                if (state == ol.TileState.ERROR) {
        //                    expect(state).to.be(ol.TileState.ERROR);
        //                    expect(tile.image_).to.be.a(HTMLCanvasElement);
        //                    ol.events.unlistenByKey(key);
        //                    tile.load();
        //                    expect(tile.image_).to.be.a(HTMLImageElement);
        //                    done();
        //                }
        //            });
        //
        //            tile.load();
        //        });
    }
    //    });
}
//
//    describe('dispose', function() {
TEST(ol_ImageTile, dispose)
{

    //it('sets image src to a blank image data uri', function() {
    {
        ol::TileCoord tileCoord = { 0, 0, 0 };
        auto state = ol::TileState::IDLE;
        std::string src = "spec/ol/data/osm-0-0-0.png";
        auto tileLoadFunction = ol::source::Image::defaultImageLoadFunction;
        auto tile = ol::ImageTile(tileCoord, state, src, std::string(), defaultLoadFunction());
        tile.load();

        EXPECT_EQ(ol::TileState::LOADING, tile.getState());

        tile.dispose();

        EXPECT_EQ(ol::TileState::ABORT, tile.getState());
        EXPECT_EQ(std::string()/*ol::ImageTile::blankImageUrl*/, tile.getImage().src());
    });

});
}
//
//});
