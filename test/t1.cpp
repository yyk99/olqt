//
//
//

#include "gtest/gtest.h"

#include <ol/Object.h>

TEST(t1, t1)
{
	ol::Object *o = new ol::Object();

	EXPECT_TRUE(o != 0);
}

#include <ol/events/EventTarget.h>

TEST(ol_events_EventTarget, t1)
{
	ol::events::EventTarget *et = new ol::events::EventTarget();
}

#include <ol/Tile.h>

TEST(ol_Tile, t1)
{
	ol::Tile *tile = new ol::Tile();
}

#include <ol/optional.h>

TEST(ol_optional, t1)
{
    ol::optional<double> od;

    EXPECT_FALSE(od.has_value());
    EXPECT_THROW(od.value(), std::runtime_error);

    od = 42.5;

    EXPECT_TRUE(od.has_value());
    EXPECT_EQ(42.5, od.value());
}


#include <ol/math.h>

//import _ol_math_ from '../../../src/ol/math.js';
//
//

TEST(math, ol_math_clamp)
{
//describe('ol.math.clamp', function() {
//
//    it('returns the correct value at -Infinity', function() {
//        expect(_ol_math_.clamp(-Infinity, 10, 20)).to.eql(10);
    EXPECT_EQ(10, ol::math::clamp(-9999, 10, 20));
//    });
//
//    it('returns the correct value at min', function() {
//        expect(_ol_math_.clamp(10, 10, 20)).to.eql(10);
    EXPECT_EQ(10, ol::math::clamp(-9999, 10, 20));
//    });
//
//    it('returns the correct value at mid point', function() {
//        expect(_ol_math_.clamp(15, 10, 20)).to.eql(15);
    EXPECT_EQ(10, ol::math::clamp(-9999, 10, 20));
//    });
//
//    it('returns the correct value at max', function() {
//        expect(_ol_math_.clamp(20, 10, 20)).to.eql(20);
    EXPECT_EQ(10, ol::math::clamp(-9999, 10, 20));
//    });
//
//    it('returns the correct value at Infinity', function() {
//        expect(_ol_math_.clamp(Infinity, 10, 20)).to.eql(20);
    EXPECT_EQ(10, ol::math::clamp(-9999, 10, 20));
//    });
//
//});
}


//describe('ol.math.cosh', function() {
//
//    it('returns the correct value at -Infinity', function() {
//        expect(_ol_math_.cosh(-Infinity)).to.eql(Infinity);
//    });
//
//    it('returns the correct value at -1', function() {
//        expect(_ol_math_.cosh(-1)).to.roughlyEqual(1.5430806348152437, 1e-9);
//    });
//
//    it('returns the correct value at 0', function() {
//        expect(_ol_math_.cosh(0)).to.eql(1);
//    });
//
//    it('returns the correct value at 1', function() {
//        expect(_ol_math_.cosh(1)).to.roughlyEqual(1.5430806348152437, 1e-9);
//    });
//
//    it('returns the correct value at Infinity', function() {
//        expect(_ol_math_.cosh(Infinity)).to.eql(Infinity);
//    });
//
//});
//
//describe('ol.math.roundUpToPowerOfTwo', function() {
//
//    it('raises an exception when x is negative', function() {
//        expect(function() {
//            _ol_math_.roundUpToPowerOfTwo(-1);
//        }).to.throwException();
//    });
//
//    it('raises an exception when x is zero', function() {
//        expect(function() {
//            _ol_math_.roundUpToPowerOfTwo(0);
//        }).to.throwException();
//    });
//
//    it('returns the expected value for simple powers of two', function() {
//        expect(_ol_math_.roundUpToPowerOfTwo(1)).to.be(1);
//        expect(_ol_math_.roundUpToPowerOfTwo(2)).to.be(2);
//        expect(_ol_math_.roundUpToPowerOfTwo(4)).to.be(4);
//        expect(_ol_math_.roundUpToPowerOfTwo(8)).to.be(8);
//        expect(_ol_math_.roundUpToPowerOfTwo(16)).to.be(16);
//        expect(_ol_math_.roundUpToPowerOfTwo(32)).to.be(32);
//        expect(_ol_math_.roundUpToPowerOfTwo(64)).to.be(64);
//        expect(_ol_math_.roundUpToPowerOfTwo(128)).to.be(128);
//        expect(_ol_math_.roundUpToPowerOfTwo(256)).to.be(256);
//    });
//
//    it('returns the expected value for simple powers of ten', function() {
//        expect(_ol_math_.roundUpToPowerOfTwo(1)).to.be(1);
//        expect(_ol_math_.roundUpToPowerOfTwo(10)).to.be(16);
//        expect(_ol_math_.roundUpToPowerOfTwo(100)).to.be(128);
//        expect(_ol_math_.roundUpToPowerOfTwo(1000)).to.be(1024);
//        expect(_ol_math_.roundUpToPowerOfTwo(10000)).to.be(16384);
//        expect(_ol_math_.roundUpToPowerOfTwo(100000)).to.be(131072);
//        expect(_ol_math_.roundUpToPowerOfTwo(1000000)).to.be(1048576);
//        expect(_ol_math_.roundUpToPowerOfTwo(10000000)).to.be(16777216);
//    });
//
//});
//
//describe('ol.math.solveLinearSystem', function() {
//
//    it('calculates correctly', function() {
//        var result = _ol_math_.solveLinearSystem([
//            [2, 1, 3, 1],
//                [2, 6, 8, 3],
//                [6, 8, 18, 5]
//        ]);
//        expect(result[0]).to.roughlyEqual(0.3, 1e-9);
//        expect(result[1]).to.roughlyEqual(0.4, 1e-9);
//        expect(result[2]).to.roughlyEqual(0, 1e-9);
//    });
//
//    it('can handle singular matrix', function() {
//        var result = _ol_math_.solveLinearSystem([
//            [2, 1, 3, 1],
//                [2, 6, 8, 3],
//                [2, 1, 3, 1]
//        ]);
//        expect(result).to.be(null);
//    });
//
//});
//
//describe('ol.math.toDegrees', function() {
//    it('returns the correct value at -π', function() {
//        expect(_ol_math_.toDegrees(-Math.PI)).to.be(-180);
//    });
//    it('returns the correct value at 0', function() {
//        expect(_ol_math_.toDegrees(0)).to.be(0);
//    });
//    it('returns the correct value at π', function() {
//        expect(_ol_math_.toDegrees(Math.PI)).to.be(180);
//    });
//});
//
//describe('ol.math.toRadians', function() {
//    it('returns the correct value at -180', function() {
//        expect(_ol_math_.toRadians(-180)).to.be(-Math.PI);
//    });
//    it('returns the correct value at 0', function() {
//        expect(_ol_math_.toRadians(0)).to.be(0);
//    });
//    it('returns the correct value at 180', function() {
//        expect(_ol_math_.toRadians(180)).to.be(Math.PI);
//    });
//});
//
//describe('ol.math.modulo', function() {
//    it('256 / 8 returns 0', function() {
//        expect(_ol_math_.modulo(256, 8)).to.be(0);
//    });
//    it('positive and positive returns a positive ', function() {
//        expect(_ol_math_.modulo(7, 8)).to.be(7);
//    });
//    it('same Dividend and Divisor returns 0', function() {
//        expect(_ol_math_.modulo(4, 4)).to.be(0);
//    });
//    it('negative and positive returns positive', function() {
//        expect(_ol_math_.modulo(-3, 4)).to.be(1);
//    });
//    it('negative and negative returns negative', function() {
//        expect(_ol_math_.modulo(-4, -5)).to.be(-4);
//        expect(_ol_math_.modulo(-3, -4)).to.be(-3);
//    });
//    it('positive and negative returns negative', function() {
//        expect(_ol_math_.modulo(3, -4)).to.be(-1);
//        expect(_ol_math_.modulo(1, -5)).to.be(-4);
//        expect(_ol_math_.modulo(6, -5)).to.be(-4);
//    });
//});
//
//describe('ol.math.lerp', function() {
//    it('correctly interpolated numbers', function() {
//        expect(_ol_math_.lerp(0, 0, 0)).to.be(0);
//        expect(_ol_math_.lerp(0, 1, 0)).to.be(0);
//        expect(_ol_math_.lerp(1, 11, 5)).to.be(51);
//    });
//    it('correctly interpolates floats', function() {
//        expect(_ol_math_.lerp(0, 1, 0.5)).to.be(0.5);
//        expect(_ol_math_.lerp(0.25, 0.75, 0.5)).to.be(0.5);
//    });
//});


#include <ol/array.h>


//
//goog.require('ol.array');
//
//
//describe('ol.array', function() {
//
//    describe('binarySearch', function() {
//
//        var insertionPoint = function(position) {
//            return -(position + 1);
//        };
//        var revNumCompare = function(a, b) {
//            return b - a;
//        };
//
//        describe('default comparison on array of String(s)', function() {
//            var a = [
//                '1000', '9', 'AB', 'ABC', 'ABCABC', 'ABD', 'ABDA', 'B', 'B', 'B',
//                    'C', 'CA', 'CC', 'ZZZ', 'ab', 'abc', 'abcabc', 'abd', 'abda', 'b',
//                    'c', 'ca', 'cc', 'zzz'
//            ];
//
//            it('should find \'1000\' at index 0', function() {
//                expect(ol.array.binarySearch(a, '1000')).to.be(0);
//            });
//            it('should find \'zzz\' at index ' + (a.length - 1), function() {
//                expect(ol.array.binarySearch(a, 'zzz')).to.be(a.length - 1);
//            });
//            it('should find \'C\' at index 10', function() {
//                expect(ol.array.binarySearch(a, 'C')).to.be(10);
//            });
//            it('should find \'B\' at index 7 || 8 || 9', function() {
//                var pos = ol.array.binarySearch(a, 'B');
//                expect(pos == 7 || pos == 8 || pos == 9).to.be.ok();
//            });
//            it('should not find \'100\'', function() {
//                var pos = ol.array.binarySearch(a, '100');
//                expect(pos < 0).to.be.ok();
//            });
//            it('should have an insertion point of 0 for \'100\'', function() {
//                var pos = ol.array.binarySearch(a, '100');
//                expect(insertionPoint(pos)).to.be(0);
//            });
//            it('should not find \'zzz0\'', function() {
//                var pos = ol.array.binarySearch(a, 'zzz0');
//                expect(pos < 0).to.be.ok();
//            });
//            it('should have an insertion point of ' + (a.length) + ' for \'zzz0\'',
//                function() {
//                var pos = ol.array.binarySearch(a, 'zzz0');
//                expect(insertionPoint(pos)).to.be(a.length);
//            }
//            );
//            it('should not find \'BA\'', function() {
//                var pos = ol.array.binarySearch(a, 'zzz0');
//                expect(pos < 0).to.be.ok();
//            });
//            it('should have an insertion point of 10 for \'BA\'',
//                function() {
//                var pos = ol.array.binarySearch(a, 'BA');
//                expect(insertionPoint(pos)).to.be(10);
//            }
//            );
//        });
//
//        describe('0 length array with default comparison', function() {
//            var b = [];
//            it('should not find \'a\'', function() {
//                expect(ol.array.binarySearch(b, 'a') < 0).to.be.ok();
//            });
//            it('should have an insertion point of 0 for \'a\'',
//                function() {
//                var pos = ol.array.binarySearch(b, 'a');
//                expect(insertionPoint(pos)).to.be(0);
//            }
//            );
//        });
//
//        describe('single element array with default lexiographical comparison',
//            function() {
//            var c = ['only item'];
//            it('should find \'only item\' at index 0', function() {
//                expect(ol.array.binarySearch(c, 'only item')).to.be(0);
//            });
//            it('should not find \'a\'', function() {
//                expect(ol.array.binarySearch(c, 'a') < 0).to.be.ok();
//            });
//            it('should have an insertion point of 0 for \'a\'',
//                function() {
//                var pos = ol.array.binarySearch(c, 'a');
//                expect(insertionPoint(pos)).to.be(0);
//            }
//            );
//            it('should not find \'z\'', function() {
//                expect(ol.array.binarySearch(c, 'z') < 0).to.be.ok();
//            });
//            it('should have an insertion point of 1 for \'z\'',
//                function() {
//                var pos = ol.array.binarySearch(c, 'z');
//                expect(insertionPoint(pos)).to.be(1);
//            }
//            );
//        }
//        );
//
//        describe('default comparison on array of Number(s)', function() {
//            var d = [
//                -897123.9, -321434.58758, -1321.3124, -324, -9, -3, 0, 0, 0,
//                    0.31255, 5, 142.88888708, 334, 342, 453, 54254
//            ];
//            it('should find -897123.9 at index 0', function() {
//                expect(ol.array.binarySearch(d, -897123.9)).to.be(0);
//            });
//            it('should find 54254 at index ' + (d.length - 1), function() {
//                expect(ol.array.binarySearch(d, 54254)).to.be(d.length - 1);
//            });
//            it('should find -3 at index 5', function() {
//                expect(ol.array.binarySearch(d, -3)).to.be(5);
//            });
//            it('should find 0 at index 6 || 7 || 8', function() {
//                var pos = ol.array.binarySearch(d, 0);
//                expect(pos == 6 || pos == 7 || pos == 8).to.be(true);
//            });
//            it('should not find -900000', function() {
//                var pos = ol.array.binarySearch(d, -900000);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of 0 for -900000', function() {
//                var pos = ol.array.binarySearch(d, -900000);
//                expect(insertionPoint(pos)).to.be(0);
//            });
//            it('should not find 54255', function() {
//                var pos = ol.array.binarySearch(d, 54255);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of ' + (d.length) + ' for 54255',
//                function() {
//                var pos = ol.array.binarySearch(d, 54255);
//                expect(insertionPoint(pos)).to.be(d.length);
//            }
//            );
//            it('should not find 1.1', function() {
//                var pos = ol.array.binarySearch(d, 1.1);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of 10 for 1.1', function() {
//                var pos = ol.array.binarySearch(d, 1.1);
//                expect(insertionPoint(pos)).to.be(10);
//            });
//        });
//
//        describe('custom comparison function, which reverse orders numbers',
//            function() {
//            var e = [
//                54254, 453, 342, 334, 142.88888708, 5, 0.31255, 0, 0, 0, -3,
//                    -9, -324, -1321.3124, -321434.58758, -897123.9
//            ];
//            it('should find 54254 at index 0', function() {
//                var pos = ol.array.binarySearch(e, 54254, revNumCompare);
//                expect(pos).to.be(0);
//            });
//            it('should find -897123.9 at index ' + (e.length - 1), function() {
//                var pos = ol.array.binarySearch(e, -897123.9, revNumCompare);
//                expect(pos).to.be(e.length - 1);
//            });
//            it('should find -3 at index 10', function() {
//                var pos = ol.array.binarySearch(e, -3, revNumCompare);
//                expect(pos).to.be(10);
//            });
//            it('should find 0 at index 7 || 8 || 9', function() {
//                var pos = ol.array.binarySearch(e, 0, revNumCompare);
//                expect(pos == 7 || pos == 8 || pos == 9).to.be(true);
//            });
//            it('should not find 54254.1', function() {
//                var pos = ol.array.binarySearch(e, 54254.1, revNumCompare);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of 0 for 54254.1', function() {
//                var pos = ol.array.binarySearch(e, 54254.1, revNumCompare);
//                expect(insertionPoint(pos)).to.be(0);
//            });
//            it('should not find -897124', function() {
//                var pos = ol.array.binarySearch(e, -897124, revNumCompare);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of ' + e.length + ' for -897124',
//                function() {
//                var pos = ol.array.binarySearch(e, -897124, revNumCompare);
//                expect(insertionPoint(pos)).to.be(e.length);
//            }
//            );
//            it('should not find 1.1', function() {
//                var pos = ol.array.binarySearch(e, 1.1, revNumCompare);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of 0 for 1.1', function() {
//                var pos = ol.array.binarySearch(e, 1.1, revNumCompare);
//                expect(insertionPoint(pos)).to.be(6);
//            });
//        }
//        );
//
//        describe('0 length array with custom comparison function', function() {
//            var f = [];
//            it('should not find 0', function() {
//                var pos = ol.array.binarySearch(f, 0, revNumCompare);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of 0 for 0', function() {
//                var pos = ol.array.binarySearch(f, 0, revNumCompare);
//                expect(insertionPoint(pos)).to.be(0);
//            });
//        });
//
//        describe('single element array with custom comparison function',
//            function() {
//            var g = [1];
//            it('should find 1 at index 0', function() {
//                var pos = ol.array.binarySearch(g, 1, revNumCompare);
//                expect(pos).to.be(0);
//            });
//            it('should not find 2', function() {
//                var pos = ol.array.binarySearch(g, 2, revNumCompare);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of 0 for 2', function() {
//                var pos = ol.array.binarySearch(g, 2, revNumCompare);
//                expect(insertionPoint(pos)).to.be(0);
//            });
//            it('should not find 0', function() {
//                var pos = ol.array.binarySearch(g, 0, revNumCompare);
//                expect(pos < 0).to.be(true);
//            });
//            it('should have an insertion point of 1 for 0', function() {
//                var pos = ol.array.binarySearch(g, 0, revNumCompare);
//                expect(insertionPoint(pos)).to.be(1);
//            });
//        }
//        );
//
//        describe('finding first index when multiple candidates', function() {
//            it('should find the index of the first 0', function() {
//                expect(ol.array.binarySearch([0, 0, 1], 0)).to.be(0);
//            });
//            it('should find the index of the first 1', function() {
//                expect(ol.array.binarySearch([0, 1, 1], 1)).to.be(1);
//            });
//        });
//
//        describe('Don\'t use Array#slice, Function#apply and Function#call',
//            function() {
//            var a = [1, 5, 7, 11, 13, 16, 19, 24, 28, 31, 33, 36, 40, 50, 52, 55];
//            var calls = {
//              'Array#slice': false,
//              'Function#apply' : false,
//              'Function#call' : false
//            };
//            var origArraySlice;
//            var origFunctionApply;
//            var origFunctionCall;
//
//            it('does not use potentially slow methods (default & custom compare)',
//                function() {
//                // Mockup (I failed to use sinon.spy and beforeEach-hooks)
//                origArraySlice = Array.prototype.slice;
//                origFunctionApply = Function.prototype.apply;
//                origFunctionCall = Function.prototype.call;
//                Array.prototype.slice = function() {
//                    calls['Array#slice'] = true;
//                };
//                Function.prototype.apply = function() {
//                    calls['Function#apply'] = true;
//                };
//                Function.prototype.call = function() {
//                    calls['Function#call'] = true;
//                };
//
//                // Now actually call and test the method twice
//                ol.array.binarySearch(a, 48);
//                ol.array.binarySearch(a, 13, function(a, b) {
//                    return a > b ? 1 : a < b ? -1 : 0;
//                });
//
//                // Restore mocked up methods
//                Array.prototype.slice = origArraySlice;
//                Function.prototype.apply = origFunctionApply;
//                Function.prototype.call = origFunctionCall;
//
//                // Expectations
//                expect(calls['Array#slice']).to.be(false);
//                expect(calls['Function#apply']).to.be(false);
//                expect(calls['Function#call']).to.be(false);
//            }
//            );
//        }
//        );
//
//        describe('when items are not found', function() {
//            var arr = [1, 2, 2, 2, 3, 5, 9];
//
//            it('should return the index of where the item would go plus one, negated, if the item is not found', function() {
//                expect(ol.array.binarySearch(arr, 4)).to.equal(-6);
//            });
//            it('should work even on empty arrays', function() {
//                expect(ol.array.binarySearch([], 42)).to.equal(-1);
//            });
//            it('should work even on arrays of doubles', function() {
//                expect(ol.array.binarySearch([0.0, 0.1, 0.2, 0.3, 0.4], 0.25)).to.equal(-4);
//            });
//        });
//    });
//
//    describe('equals', function() {
//        it('returns true for [] == []', function() {
//            expect(ol.array.equals([], [])).to.be(true);
//        });
//        it('returns true for [1] == [1]', function() {
//            expect(ol.array.equals([1], [1])).to.be(true);
//        });
//        it('returns true for [\'1\'] == [\'1\']', function() {
//            expect(ol.array.equals(['1'], ['1'])).to.be(true);
//        });
//        it('returns false for [1] == [\'1\']', function() {
//            expect(ol.array.equals([1], ['1'])).to.be(false);
//        });
//        it('returns true for [null] == [null]', function() {
//            expect(ol.array.equals([null], [null])).to.be(true);
//        });
//        it('returns false for [null] == [undefined]', function() {
//            expect(ol.array.equals([null], [undefined])).to.be(false);
//        });
//        it('returns true for [1, 2] == [1, 2]', function() {
//            expect(ol.array.equals([1, 2], [1, 2])).to.be(true);
//        });
//        it('returns false for [1, 2] == [2, 1]', function() {
//            expect(ol.array.equals([1, 2], [2, 1])).to.be(false);
//        });
//        it('returns false for [1, 2] == [1]', function() {
//            expect(ol.array.equals([1, 2], [1])).to.be(false);
//        });
//        it('returns false for [1] == [1, 2]', function() {
//            expect(ol.array.equals([1], [1, 2])).to.be(false);
//        });
//        it('returns false for [{}] == [{}]', function() {
//            expect(ol.array.equals([{}], [{}])).to.be(false);
//        });
//    });
//    describe('extend', function() {
//        it('extends an array in place with an array', function() {
//            var a = [0, 1];
//            ol.array.extend(a, [2, 3]);
//            expect(a).to.eql([0, 1, 2, 3]);
//        });
//        it('extends an array in place with a number', function() {
//            var a = [0, 1];
//            ol.array.extend(a, 2);
//            expect(a).to.eql([0, 1, 2]);
//        });
//        it('extends an array in place with a big array', function() {
//            var a = [];
//            var i = 250000; // original test has 1.000.000, but that was too slow
//            var bigArray = Array(i);
//            while (i--) {
//                bigArray[i] = i;
//            }
//            ol.array.extend(a, bigArray);
//            expect(a).to.eql(bigArray);
//        });
//    });
//
//    describe('find', function() {
//        it('finds numbers in an array', function() {
//            var a = [0, 1, 2, 3];
//            var b = ol.array.find(a, function(val, index, a2) {
//                expect(a).to.equal(a2);
//                expect(typeof index).to.be('number');
//                return val > 1;
//            });
//            expect(b).to.be(2);
//        });
//
//        it('returns null when an item in an array is not found', function() {
//            var a = [0, 1, 2, 3];
//            var b = ol.array.find(a, function(val, index, a2) {
//                return val > 100;
//            });
//            expect(b).to.be(null);
//        });
//
//        it('finds items in an array-like', function() {
//            var a = 'abCD';
//            var b = ol.array.find(a, function(val, index, a2) {
//                expect(a).to.equal(a2);
//                expect(typeof index).to.be('number');
//                return val >= 'A' && val <= 'Z';
//            });
//            expect(b).to.be('C');
//        });
//
//        it('returns null when nothing in an array-like is found', function() {
//            var a = 'abcd';
//            var b = ol.array.find(a, function(val, index, a2) {
//                return val >= 'A' && val <= 'Z';
//            });
//            expect(b).to.be(null);
//        });
//    });
//
//    describe('findIndex', function() {
//        it('finds index of numbers in an array', function() {
//            var a = [0, 1, 2, 3];
//            var b = ol.array.findIndex(a, function(val, index, a2) {
//                expect(a).to.equal(a2);
//                expect(typeof index).to.be('number');
//                return val > 1;
//            });
//            expect(b).to.be(2);
//        });
//
//        it('returns -1 when an item in an array is not found', function() {
//            var a = [0, 1, 2, 3];
//            var b = ol.array.findIndex(a, function(val, index, a2) {
//                return val > 100;
//            });
//            expect(b).to.be(-1);
//        });
//    });
//
//    describe('isSorted', function() {
//        it('works with just an array as argument', function() {
//            expect(ol.array.isSorted([1, 2, 3])).to.be(true);
//            expect(ol.array.isSorted([1, 2, 2])).to.be(true);
//            expect(ol.array.isSorted([1, 2, 1])).to.be(false);
//        });
//
//        it('works with strict comparison without compare function', function() {
//            expect(ol.array.isSorted([1, 2, 3], null, true)).to.be(true);
//            expect(ol.array.isSorted([1, 2, 2], null, true)).to.be(false);
//            expect(ol.array.isSorted([1, 2, 1], null, true)).to.be(false);
//        });
//
//        it('works with a compare function', function() {
//            function compare(a, b) {
//                return b - a;
//            }
//            expect(ol.array.isSorted([1, 2, 3], compare)).to.be(false);
//            expect(ol.array.isSorted([3, 2, 2], compare)).to.be(true);
//        });
//    });

TEST(ol_array, linearFindNearest)
{
    using namespace ol::array;
//    describe('linearFindNearest', function() {
//        it('returns expected value', function() {
//            var arr = [1000, 500, 100];
    std::vector<int> arr({ 1000, 500, 100 });
//
//            expect(ol.array.linearFindNearest(arr, 10000, 0)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 10000, 1)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 10000, -1)).to.eql(0);
    EXPECT_EQ(0, linearFindNearest(arr, 10000, 0));
    EXPECT_EQ(0, linearFindNearest(arr, 10000, 1));
    EXPECT_EQ(0, linearFindNearest(arr, 10000, -1));
//
//            expect(ol.array.linearFindNearest(arr, 1000, 0)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 1000, 1)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 1000, -1)).to.eql(0);
    EXPECT_EQ(0, linearFindNearest(arr, 1000, 0));
    EXPECT_EQ(0, linearFindNearest(arr, 1000, 1));
    EXPECT_EQ(0, linearFindNearest(arr, 1000, -1));
//
//            expect(ol.array.linearFindNearest(arr, 900, 0)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 900, 1)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 900, -1)).to.eql(1);
    EXPECT_EQ(0, linearFindNearest(arr, 900, 0));
    EXPECT_EQ(0, linearFindNearest(arr, 900, 1));
    EXPECT_EQ(1, linearFindNearest(arr, 900, -1));
//
//            expect(ol.array.linearFindNearest(arr, 750, 0)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 750, 1)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 750, -1)).to.eql(1);
    EXPECT_EQ(1, linearFindNearest(arr, 750, 0));
    EXPECT_EQ(0, linearFindNearest(arr, 750, 1));
    EXPECT_EQ(1, linearFindNearest(arr, 750, -1));
//
//            expect(ol.array.linearFindNearest(arr, 550, 0)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 550, 1)).to.eql(0);
//            expect(ol.array.linearFindNearest(arr, 550, -1)).to.eql(1);
    EXPECT_EQ(1, linearFindNearest(arr, 550, 0));
    EXPECT_EQ(0, linearFindNearest(arr, 550, 1));
    EXPECT_EQ(1, linearFindNearest(arr, 550, -1));
//
//            expect(ol.array.linearFindNearest(arr, 500, 0)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 500, 1)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 500, -1)).to.eql(1);
    EXPECT_EQ(1, linearFindNearest(arr, 500, 0));
    EXPECT_EQ(1, linearFindNearest(arr, 500, 1));
    EXPECT_EQ(1, linearFindNearest(arr, 500, -1));
//
//            expect(ol.array.linearFindNearest(arr, 450, 0)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 450, 1)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 450, -1)).to.eql(2);
    EXPECT_EQ(1, linearFindNearest(arr, 450, 0));
    EXPECT_EQ(1, linearFindNearest(arr, 450, 1));
    EXPECT_EQ(2, linearFindNearest(arr, 450, -1));
//
//            expect(ol.array.linearFindNearest(arr, 300, 0)).to.eql(2);
//            expect(ol.array.linearFindNearest(arr, 300, 1)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 300, -1)).to.eql(2);
    EXPECT_EQ(2, linearFindNearest(arr, 300, 0));
    EXPECT_EQ(1, linearFindNearest(arr, 300, 1));
    EXPECT_EQ(2, linearFindNearest(arr, 300, -1));
//
//            expect(ol.array.linearFindNearest(arr, 200, 0)).to.eql(2);
//            expect(ol.array.linearFindNearest(arr, 200, 1)).to.eql(1);
//            expect(ol.array.linearFindNearest(arr, 200, -1)).to.eql(2);
    EXPECT_EQ(2, linearFindNearest(arr, 200, 0));
    EXPECT_EQ(1, linearFindNearest(arr, 200, 1));
    EXPECT_EQ(2, linearFindNearest(arr, 200, -1));
//            expect(ol.array.linearFindNearest(arr, 100, 0)).to.eql(2);
//            expect(ol.array.linearFindNearest(arr, 100, 1)).to.eql(2);
//            expect(ol.array.linearFindNearest(arr, 100, -1)).to.eql(2);
    EXPECT_EQ(2, linearFindNearest(arr, 100, 0));
    EXPECT_EQ(2, linearFindNearest(arr, 100, 1));
    EXPECT_EQ(2, linearFindNearest(arr, 100, -1));
//            expect(ol.array.linearFindNearest(arr, 50, 0)).to.eql(2);
//            expect(ol.array.linearFindNearest(arr, 50, 1)).to.eql(2);
//            expect(ol.array.linearFindNearest(arr, 50, -1)).to.eql(2);
    EXPECT_EQ(2, linearFindNearest(arr, 50, 0));
    EXPECT_EQ(2, linearFindNearest(arr, 50, 1));
    EXPECT_EQ(2, linearFindNearest(arr, 50, -1));
}

//    describe('numberSafeCompareFunction', function() {
//        it('sorts as expected', function() {
//            var arr = [40, 200, 3000];
//            // default sort would yield [200, 3000, 40]
//            arr.sort(ol.array.numberSafeCompareFunction);
//            expect(arr).to.eql(arr);
//        });
//    });
//
//    describe('remove', function() {
//        it('removes elements from an array', function() {
//            var a = ['a', 'b', 'c', 'd'];
//            ol.array.remove(a, 'c');
//            expect(a).to.eql(['a', 'b', 'd']);
//            ol.array.remove(a, 'x');
//            expect(a).to.eql(['a', 'b', 'd']);
//        });
//    });
//
//    describe('reverseSubArray', function() {
//        it('returns expected value', function() {
//            var arr;
//            var expected = [1, 2, 3, 4, 5, 6];
//
//            arr = [1, 5, 4, 3, 2, 6];
//            ol.array.reverseSubArray(arr, 1, 4);
//            expect(arr).to.eql(expected);
//
//            arr = [3, 2, 1, 4, 5, 6];
//            ol.array.reverseSubArray(arr, 0, 2);
//            expect(arr).to.eql(expected);
//
//            arr = [1, 2, 3, 6, 5, 4];
//            ol.array.reverseSubArray(arr, 3, 5);
//            expect(arr).to.eql(expected);
//
//            arr = [6, 5, 4, 3, 2, 1];
//            ol.array.reverseSubArray(arr, 0, 5);
//            expect(arr).to.eql(expected);
//        });
//    });
//
//    describe('stableSort', function() {
//        var arr, wantedSortedValues;
//
//        beforeEach(function() {
//            arr = [{key: 3, val : 'a'}, { key: 2, val : 'b' }, { key: 3, val : 'c' },
//            { key: 4, val : 'd' }, { key: 3, val : 'e' }];
//            wantedSortedValues = ['b', 'a', 'c', 'e', 'd'];
//        });
//
//        it('works on an array with custom comparison function', function() {
//            function comparisonFn(obj1, obj2) {
//                return obj1.key - obj2.key;
//            }
//            ol.array.stableSort(arr, comparisonFn);
//            var sortedValues = [];
//            for (var i = 0; i < arr.length; i++) {
//                sortedValues.push(arr[i].val);
//            }
//            expect(wantedSortedValues).to.eql(sortedValues);
//        });
//    });
//
//});
