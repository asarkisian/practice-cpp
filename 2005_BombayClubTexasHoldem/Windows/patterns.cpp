///////////////////////////////////////
// patterns.cpp

///////////////////////////////////////
#include "poker.h"
///////////////////////////////////////

///////////////////////////////////////
using std::domain_error;
using std::vector;
///////////////////////////////////////

///////////////////////////////////////
void Poker::checkPattern( name_t who )
{
	uint_t score = ( 0 );

	if( isRoyalFlush( who ) ) { score = 10; }
	else if( isStraightFlush( who ) ) { score = 9; }
	else if( isFourKind( who ) ) { score = 8; }
	else if( isFullHouse( who ) ) { score = 7; }
	else if( isFlush( who ) ) { score = 6; }
	else if( isStraight( who ) ) { score = 5; }
	else if( isThreeKind( who ) ) { score = 4; }
	else if( isTwoPair( who ) ) { score = 3; }
	else if( isPair( who ) ) { score = 2; }
	else { score = 1; }
	
	highCard( who );
	
	if( who == PLAYER ) { my_playersScore = ( score ); }
	else if( who == DEALER ) { my_dealersScore = ( score ); }
	else { throw domain_error( ERROR_101 ); }
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isRoyalFlush( name_t who ) const
{
	vector<bool> my_emptyArray( EMPTY_ARRAY, false );
	bool isFlush = ( false ), isStraight = ( false );

	uint_t depth = ( 0 );

	// straight counter
	uint_t straightCounter = ( 0 );  // if 5 or more than straight

	// flush counters
	uint_t spadeCounter = ( 0 ), heartCounter = ( 0 ),
		diamondCounter = ( 0 ), clubCounter = ( 0 );

	// Check # 1
	// ensure that the user has atleast a flush
	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST )
			{
				if( my_playersHand->at( i )->at( 2 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
			else
			{
				if( my_playersHand->at( i )->at( 1 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
		}
	}else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST )
			{
				if( my_dealersHand->at( i )->at( 2 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
			else
			{
				if( my_dealersHand->at( i )->at( 1 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
		}
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST )
		{
			if( my_sharedHand.at( i ).at( 2 ) == '\x3' )
			{
				++heartCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x4' )
			{
				++diamondCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x5' )
			{
				++clubCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x6' )
			{
				++spadeCounter;
			}
		}
		else
		{
			if( my_sharedHand.at( i ).at( 1 ) == '\x3' )
			{
				++heartCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x4' )
			{
				++diamondCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x5' )
			{
				++clubCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x6' )
			{
				++spadeCounter;
			}
		}
	}

	if( ( heartCounter > 4 ) || ( spadeCounter > 4 )
	||  ( clubCounter > 4 ) || ( diamondCounter > 4 ) )
	{
		isFlush = ( true ); // player has the flush portion
	}

	// If the player does not have a flush, there is no way they can get a RF
	if( !isFlush )
		return false;

	// Check # 2
	// ensure that the user has a straight

	// At this point, the player has a flush.. checking for the straight now
	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == ACE ){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == ACE ){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == ACE ){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

	} // end of for-loop

	// check the empty array now for five consecutive 1's
	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( straightCounter > 4 )
		{
			isStraight = ( true );
			break;
		}

		if( my_emptyArray.at( i ) == true ){ ++straightCounter; }
		else { straightCounter = 0; }
	} // end of for-loop

	if( !isStraight )
		return false;

	// Check # 3
	// ensure that the user has a straight that starts with a 10
	if( my_emptyArray.at( 10 ) && my_emptyArray.at( 11 )
	&&  my_emptyArray.at( 12 ) && my_emptyArray.at( 13 )
	&&  my_emptyArray.at( 14 ) )
	{
		depth = ( 14 );

		// send the depth to either the player or the dealer
		if( who == PLAYER ){ my_playersDepth = ( depth ); }
		else if( who == DEALER ){ my_dealersDepth = ( depth ); }
		else
		{
			throw domain_error( ERROR_101 );
		}

		return( true ); // player has a royal flush
	}

	// has a straight flush but not a royal flush so returning false
	return( false );
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isStraightFlush( name_t who ) const
{
	vector<bool> my_emptyArray( EMPTY_ARRAY, false );
	bool isFlush = ( false ), isStraight = ( false );

	uint_t depth = ( 0 );

	// straight counter
	uint_t straightCounter = ( 0 );  // if 5 or more than straight

	// flush counters
	uint_t spadeCounter = ( 0 ), heartCounter = ( 0 ),
		diamondCounter = ( 0 ), clubCounter = ( 0 );

	// Check # 1
	// ensure that the user has atleast a flush
	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST )
			{
				if( my_playersHand->at( i )->at( 2 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
			else
			{
				if( my_playersHand->at( i )->at( 1 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
		}
	}else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST )
			{
				if( my_dealersHand->at( i )->at( 2 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
			else
			{
				if( my_dealersHand->at( i )->at( 1 ) == '\x3' )
				{
					++heartCounter;
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x4' )
				{
					++diamondCounter;
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x5' )
				{
					++clubCounter;
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x6' )
				{
					++spadeCounter;
				}
			}
		}
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST )
		{
			if( my_sharedHand.at( i ).at( 2 ) == '\x3' )
			{
				++heartCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x4' )
			{
				++diamondCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x5' )
			{
				++clubCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x6' )
			{
				++spadeCounter;
			}
		}
		else
		{
			if( my_sharedHand.at( i ).at( 1 ) == '\x3' )
			{
				++heartCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x4' )
			{
				++diamondCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x5' )
			{
				++clubCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x6' )
			{
				++spadeCounter;
			}
		}
	}

	if( ( heartCounter > 4 ) || ( spadeCounter > 4 )
	||  ( clubCounter > 4 ) || ( diamondCounter > 4 ) )
	{
		isFlush = ( true ); // player has the flush portion
	}

	// If the player does not have a flush, there is no way they can get a RF
	if( !isFlush )
		return false;

	// Check # 2
	// ensure that the user has a straight

	// At this point, the player has a flush.. checking for the straight now
	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == ACE ){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == ACE ){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == ACE ){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

	} // end of for-loop

	// check the empty array now for five consecutive 1's
	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( straightCounter > 4 )
		{
			isStraight = ( true ); // player has a straight
		}

		if( my_emptyArray.at( i ) == true ){ ++straightCounter; }
		else { straightCounter = 0; }
	} // end of for-loop

	if( !isStraight )
	{
		return( false );
	}

	// Now we know the user has a straight flush.. checking for depth
	for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
	{
		if( my_playersHand->at( i )->at( 0 ) == ACE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == KING )
				{
					depth = 14;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == ACE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == KING )
				{
					depth = 14;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == KING )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == QUEEN )
				{
					depth = 13;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == KING )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == QUEEN )
				{
					depth = 13;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == QUEEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == JACK )
				{
					depth = 12;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == QUEEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == JACK )
				{
					depth = 12;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == JACK )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TEN_SUBST )
				{
					depth = 11;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == JACK )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TEN_SUBST )
				{
					depth = 11;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == NINE )
				{
					depth = 10;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == TEN_SUBST )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == NINE )
				{
					depth = 10;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == NINE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == EIGHT )
				{
					depth = 9;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == NINE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == EIGHT )
				{
					depth = 9;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == EIGHT )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SEVEN )
				{
					depth = 8;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == EIGHT )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SEVEN )
				{
					depth = 8;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == SEVEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SIX )
				{
					depth = 7;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == SEVEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SIX )
				{
					depth = 7;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == SIX )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FIVE )
				{
					depth = 6;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == SIX )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FIVE )
				{
					depth = 6;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == FIVE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FOUR )
				{
					depth = 5;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == FIVE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FOUR )
				{
					depth = 5;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == FOUR )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == THREE )
				{
					depth = 4;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == FOUR )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == THREE )
				{
					depth = 4;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == THREE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TWO )
				{
					depth = 3;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == THREE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TWO )
				{
					depth = 3;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == TWO )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == ACE )
				{
					depth = 2;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == TWO )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == ACE )
				{
					depth = 2;
					break;
				}
			} // end of for-loop
		}

	} // end of for-loop

	// send the depth to either the player or the dealer
	if( who == PLAYER ){ my_playersDepth = ( depth ); }
	else if( who == DEALER ){ my_dealersDepth = ( depth ); }
	else
	{
		throw domain_error( ERROR_101 );
	}

	return( true );
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isFourKind( name_t who ) const
{
	vector<int> my_emptyArray( EMPTY_ARRAY, 0 );

	uint_t depth = ( 0 );

	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_playersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_playersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
	
	} // end of for-loop

	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( my_emptyArray.at( i ) == 4 )
		{
			depth = ( i + 2 );

			// send the depth to either the player or the dealer
			if( who == PLAYER ){ my_playersDepth = ( depth ); }
			else if( who == DEALER ){ my_dealersDepth = ( depth ); }
			else
			{
				throw domain_error( ERROR_101 );
			}

			return( true ); // player has 4 of a kind
		}

	} // end of for-loop

	return( false );
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isFullHouse( name_t who ) const
{
	vector<int> my_emptyArray( EMPTY_ARRAY, 0 );
	bool isPair = ( false ), isThreeKind = ( false );

	uint_t depth = ( 0 );

	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_playersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_playersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
	
	} // end of for-loop

	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( my_emptyArray.at( i ) == 3 )
		{			
			depth = ( i + 2 );
			isThreeKind = ( true );
		}
		else if( my_emptyArray.at( i ) == 2 )
		{
			isPair = ( true );
		}
	} // end of for-loop

	if( isThreeKind && isPair )
	{ 
		// send the depth to either the player or the dealer
		if( who == PLAYER ){ my_playersDepth = ( depth ); }
		else if( who == DEALER ){ my_dealersDepth = ( depth ); }
		else
		{
			throw domain_error( ERROR_101 );
		}

		return( true ); // has a full house
	}

	return( false );
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isFlush( name_t who ) const
{
	// flush counters
	uint_t spadeCounter = ( 0 ), heartCounter = ( 0 );
	uint_t diamondCounter = ( 0 ), clubCounter = ( 0 );

	uint_t depth = ( 0 );

	// check for flush on the communal hand first
	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST )
		{
			if( my_sharedHand.at( i ).at( 2 ) == '\x3' )
			{
				++heartCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x4' )
			{
				++diamondCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x5' )
			{
				++clubCounter;
			}
			else if( my_sharedHand.at( i ).at( 2 ) == '\x6' )
			{
				++spadeCounter;
			}
		}
		else
		{
			if( my_sharedHand.at( i ).at( 1 ) == '\x3' )
			{
				++heartCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x4' )
			{
				++diamondCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x5' )
			{
				++clubCounter;
			}
			else if( my_sharedHand.at( i ).at( 1 ) == '\x6' )
			{
				++spadeCounter;
			}
		}
	}

	// ensure that the user has a flush
	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST )
			{
				if( my_playersHand->at( i )->at( 2 ) == '\x3' )
				{
					++heartCounter;

					if( heartCounter > 4 ){ depth = 10; }
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x4' )
				{
					++diamondCounter;

					if( diamondCounter > 4 ){ depth = 10; }
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x5' )
				{
					++clubCounter;

					if( clubCounter > 4 ){ depth = 10; }
				}
				else if( my_playersHand->at( i )->at( 2 ) == '\x6' )
				{
					++spadeCounter;

					if( spadeCounter > 4 ){ depth = 10; }
				}
			}
			else
			{
				if( my_playersHand->at( i )->at( 1 ) == '\x3' )
				{
					++heartCounter;

					if( heartCounter > 4 )
					{
						if( my_playersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_playersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_playersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_playersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_playersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_playersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_playersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x4' )
				{
					++diamondCounter;

					if( diamondCounter > 4 )
					{
						if( my_playersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_playersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_playersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_playersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_playersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_playersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_playersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x5' )
				{
					++clubCounter;

					if( clubCounter > 4 )
					{
						if( my_playersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_playersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_playersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_playersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_playersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_playersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_playersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
				else if( my_playersHand->at( i )->at( 1 ) == '\x6' )
				{
					++spadeCounter;
					
					if( spadeCounter > 4 )
					{
						if( my_playersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_playersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_playersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_playersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_playersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_playersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_playersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
			}
		}
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST )
			{
				if( my_dealersHand->at( i )->at( 2 ) == '\x3' )
				{
					++heartCounter;

					if( heartCounter > 4 ){ depth = 10; }
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x4' )
				{
					++diamondCounter;

					if( diamondCounter > 4 ){ depth = 10; }
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x5' )
				{
					++clubCounter;

					if( clubCounter > 4 ){ depth = 10; }
				}
				else if( my_dealersHand->at( i )->at( 2 ) == '\x6' )
				{
					++spadeCounter;

					if( spadeCounter > 4 ){ depth = 10; }
				}
			}
			else
			{
				if( my_dealersHand->at( i )->at( 1 ) == '\x3' )
				{
					++heartCounter;

					if( heartCounter > 4 )
					{
						if( my_dealersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_dealersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x4' )
				{
					++diamondCounter;

					if( diamondCounter > 4 )
					{
						if( my_dealersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_dealersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x5' )
				{
					++clubCounter;

					if( clubCounter > 4 )
					{
						if( my_dealersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_dealersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
				else if( my_dealersHand->at( i )->at( 1 ) == '\x6' )
				{
					++spadeCounter;
					
					if( spadeCounter > 4 )
					{
						if( my_dealersHand->at( i )->at( 0 ) == TWO ){ depth = 2; }
						else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ depth = 3; }
						else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ depth = 4; }
						else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ depth = 5; }
						else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ depth = 6; }
						else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ depth = 7; }
						else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ depth = 8; }
						else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ depth = 9; }
						else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ depth = 10; }
						else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ depth = 11; }
						else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ depth = 12; }
						else if( my_dealersHand->at( i )->at( 0 ) == KING ){ depth = 13; }
						else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ depth = 14; }
					}
				}
			}
		}
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	// send the depth to either the player or the dealer
	if( who == PLAYER ){ my_playersDepth = ( depth ); }
	else if( who == DEALER ){ my_dealersDepth = ( depth ); }
	else { throw domain_error( ERROR_101 ); }

	if( ( heartCounter > 4 ) || ( spadeCounter > 4 )
	||  ( clubCounter > 4 ) || ( diamondCounter > 4 ) )
	{
		return( true ); // player has a flush
	}

	return( false );
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isStraight( name_t who ) const
{
	vector<bool> my_emptyArray( EMPTY_ARRAY, false );
	bool isStraight = ( false );

	uint_t depth = ( 0 );

	// straight counter
	uint_t straightCounter = ( 0 );  // if 5 or more than straight

	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == ACE){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
			else if( my_playersHand->at( i )->at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == ACE){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == ACE){ my_emptyArray.at( 1 ) = true; my_emptyArray.at( 14 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == TWO ) { my_emptyArray.at( 2 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ) { my_emptyArray.at( 3 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ) { my_emptyArray.at( 4 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ) { my_emptyArray.at( 5 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ) { my_emptyArray.at( 6 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ) { my_emptyArray.at( 7 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ) { my_emptyArray.at( 8 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ) { my_emptyArray.at( 9 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ) { my_emptyArray.at( 10 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ) { my_emptyArray.at( 11 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ) { my_emptyArray.at( 12 ) = true; }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ) { my_emptyArray.at( 13 ) = true; }

	} // end of for-loop

	// check the empty array now for five consecutive 1's
	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( straightCounter > 4 )
		{
			isStraight = ( true );
		}

		if( my_emptyArray.at( i ) == true ){ ++straightCounter; }
		else { straightCounter = 0; }
	} // end of for-loop

	if( !isStraight )
		return( false );

	// Now we know the user has a straight.. checking for depth
	for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
	{
		if( my_playersHand->at( i )->at( 0 ) == ACE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == KING )
				{
					depth = 14;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == ACE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == KING )
				{
					depth = 14;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == KING )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == QUEEN )
				{
					depth = 13;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == KING )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == QUEEN )
				{
					depth = 13;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == QUEEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == JACK )
				{
					depth = 12;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == QUEEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == JACK )
				{
					depth = 12;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == JACK )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TEN_SUBST )
				{
					depth = 11;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == JACK )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TEN_SUBST )
				{
					depth = 11;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == NINE )
				{
					depth = 10;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == TEN_SUBST )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == NINE )
				{
					depth = 10;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == NINE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == EIGHT )
				{
					depth = 9;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == NINE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == EIGHT )
				{
					depth = 9;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == EIGHT )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SEVEN )
				{
					depth = 8;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == EIGHT )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SEVEN )
				{
					depth = 8;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == SEVEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SIX )
				{
					depth = 7;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == SEVEN )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == SIX )
				{
					depth = 7;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == SIX )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FIVE )
				{
					depth = 6;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == SIX )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FIVE )
				{
					depth = 6;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == FIVE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FOUR )
				{
					depth = 5;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == FIVE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == FOUR )
				{
					depth = 5;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == FOUR )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == THREE )
				{
					depth = 4;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == FOUR )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == THREE )
				{
					depth = 4;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == THREE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TWO )
				{
					depth = 3;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == THREE )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == TWO )
				{
					depth = 3;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 0 ) == TWO )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == ACE )
				{
					depth = 2;
					break;
				}
			} // end of for-loop
		}
		else if( my_playersHand->at( i )->at( 1 ) == TWO )
		{
			for( uint_t x = ( 0 ); x < my_sharedHand.size( ); ++x )
			{
				if( my_sharedHand.at( x ).at( 0 ) == ACE )
				{
					depth = 2;
					break;
				}
			} // end of for-loop
		}

	} // end of for-loop

	// send the depth to either the player or the dealer
	if( who == PLAYER ){ my_playersDepth = ( depth ); }
	else if( who == DEALER ){ my_dealersDepth = ( depth ); }
	else
	{
		throw domain_error( ERROR_101 );
	}

	return( true ); // player has a straight
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isThreeKind( name_t who ) const
{
	vector<int> my_emptyArray( EMPTY_ARRAY, 0 );
	uint_t depth = ( 0 );

	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_playersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_playersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
	
	} // end of for-loop

	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( my_emptyArray.at( i ) == 3 )
		{
			depth = ( i + 2 );

			// send the depth to either the player or the dealer
			if( who == PLAYER ){ my_playersDepth = ( depth ); }
			else if( who == DEALER ){ my_dealersDepth = ( depth ); }
			else
			{
				throw domain_error( ERROR_101 );
			}

			return( true );
		}
	} // end of for-loop

	return( false );
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isTwoPair( name_t who ) const
{
	vector<int> my_emptyArray( EMPTY_ARRAY, 0 );
	uint_t pairCounter = ( 0 );

	uint_t depth = ( 0 );

	// for the communal hand
	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
	
	} // end of for-loop


	// check for the player/dealer now
	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TWO )
			{ 
				++my_emptyArray.at( 2 ); 

				if( my_emptyArray.at( 2 ) > 1 )
				{
					// pair detected
					depth = 2;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == THREE )
			{ 
				++my_emptyArray.at( 3 ); 

				if( my_emptyArray.at( 3 ) > 1 )
				{
					// pair detected
					depth = 3;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == FOUR )
			{ 
				++my_emptyArray.at( 4 ); 

				if( my_emptyArray.at( 4 ) > 1 )
				{
					// pair detected
					depth = 4;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == FIVE )
			{ 
				++my_emptyArray.at( 5 ); 

				if( my_emptyArray.at( 5 ) > 1 )
				{
					// pair detected
					depth = 5;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == SIX )
			{ 
				++my_emptyArray.at( 6 ); 

				if( my_emptyArray.at( 6 ) > 1 )
				{
					// pair detected
					depth = 6;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN )
			{ 
				++my_emptyArray.at( 7 ); 

				if( my_emptyArray.at( 7 ) > 1 )
				{
					// pair detected
					depth = 7;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT )
			{ 
				++my_emptyArray.at( 8 ); 

				if( my_emptyArray.at( 8 ) > 1 )
				{
					// pair detected
					depth = 8;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == NINE )
			{ 
				++my_emptyArray.at( 9 ); 

				if( my_emptyArray.at( 9 ) > 1 )
				{
					// pair detected
					depth = 9;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST )
			{ 
				++my_emptyArray.at( 10 ); 

				if( my_emptyArray.at( 10 ) > 1 )
				{
					// pair detected
					depth = 10;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == JACK )
			{ 
				++my_emptyArray.at( 11 ); 

				if( my_emptyArray.at( 11 ) > 1 )
				{
					// pair detected
					depth = 11;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN )
			{ 
				++my_emptyArray.at( 12 ); 

				if( my_emptyArray.at( 12 ) > 1 )
				{
					// pair detected
					depth = 12;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == KING )
			{ 
				++my_emptyArray.at( 13 ); 

				if( my_emptyArray.at( 13 ) > 1 )
				{
					// pair detected
					depth = 13;
				}
			}
			else if( my_playersHand->at( i )->at( 0 ) == ACE )
			{ 
				++my_emptyArray.at( 14 ); 

				if( my_emptyArray.at( 14 ) > 1 )
				{
					// pair detected
					depth = 14;
				}
			}
		
		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TWO )
			{ 
				++my_emptyArray.at( 2 ); 

				if( my_emptyArray.at( 2 ) > 1 )
				{
					// pair detected
					depth = 2;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == THREE )
			{ 
				++my_emptyArray.at( 3 ); 

				if( my_emptyArray.at( 3 ) > 1 )
				{
					// pair detected
					depth = 3;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR )
			{ 
				++my_emptyArray.at( 4 ); 

				if( my_emptyArray.at( 4 ) > 1 )
				{
					// pair detected
					depth = 4;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE )
			{ 
				++my_emptyArray.at( 5 ); 

				if( my_emptyArray.at( 5 ) > 1 )
				{
					// pair detected
					depth = 5;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == SIX )
			{ 
				++my_emptyArray.at( 6 ); 

				if( my_emptyArray.at( 6 ) > 1 )
				{
					// pair detected
					depth = 6;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN )
			{ 
				++my_emptyArray.at( 7 ); 

				if( my_emptyArray.at( 7 ) > 1 )
				{
					// pair detected
					depth = 7;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT )
			{ 
				++my_emptyArray.at( 8 ); 

				if( my_emptyArray.at( 8 ) > 1 )
				{
					// pair detected
					depth = 8;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == NINE )
			{ 
				++my_emptyArray.at( 9 ); 

				if( my_emptyArray.at( 9 ) > 1 )
				{
					// pair detected
					depth = 9;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST )
			{ 
				++my_emptyArray.at( 10 ); 

				if( my_emptyArray.at( 10 ) > 1 )
				{
					// pair detected
					depth = 10;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == JACK )
			{ 
				++my_emptyArray.at( 11 ); 

				if( my_emptyArray.at( 11 ) > 1 )
				{
					// pair detected
					depth = 11;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN )
			{ 
				++my_emptyArray.at( 12 ); 

				if( my_emptyArray.at( 12 ) > 1 )
				{
					// pair detected
					depth = 12;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == KING )
			{ 
				++my_emptyArray.at( 13 ); 

				if( my_emptyArray.at( 13 ) > 1 )
				{
					// pair detected
					depth = 13;
				}
			}
			else if( my_dealersHand->at( i )->at( 0 ) == ACE )
			{ 
				++my_emptyArray.at( 14 ); 

				if( my_emptyArray.at( 14 ) > 1 )
				{
					// pair detected
					depth = 14;
				}
			}
		
		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( my_emptyArray.at( i ) == 2 ) { ++pairCounter; }
	} // end of for-loop

	if( pairCounter > 1 )
	{ 
		return( true ); // player does have a two pair
	}

	return( false );
}
///////////////////////////////////////

///////////////////////////////////////
bool Poker::isPair( name_t who ) const
{
	vector<int> my_emptyArray( EMPTY_ARRAY, 0 );

	uint_t depth = ( 0 );

	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_playersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_playersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
			else if( my_dealersHand->at( i )->at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
		
		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( uint_t i = ( 0 ); i < my_sharedHand.size( ); ++i )
	{
		if( my_sharedHand.at( i ).at( 0 ) == TWO ){ ++my_emptyArray.at( 2 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == THREE ){ ++my_emptyArray.at( 3 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FOUR ){ ++my_emptyArray.at( 4 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == FIVE ){ ++my_emptyArray.at( 5 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SIX ){ ++my_emptyArray.at( 6 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == SEVEN ){ ++my_emptyArray.at( 7 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == EIGHT ){ ++my_emptyArray.at( 8 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == NINE ){ ++my_emptyArray.at( 9 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == TEN_SUBST ){ ++my_emptyArray.at( 10 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == JACK ){ ++my_emptyArray.at( 11 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == QUEEN ){ ++my_emptyArray.at( 12 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == KING ){ ++my_emptyArray.at( 13 ); }
		else if( my_sharedHand.at( i ).at( 0 ) == ACE ){ ++my_emptyArray.at( 14 ); }
	
	} // end of for-loop

	for( uint_t i = ( 0 ); i < my_emptyArray.size( ); ++i )
	{
		if( my_emptyArray.at( i ) == 2 )
		{
			depth = ( i + 2 );

			// send the depth to either the player or the dealer
			if( who == PLAYER ){ my_playersDepth = ( depth ); }
			else if( who == DEALER ){ my_dealersDepth = ( depth ); }
			else
			{
				throw domain_error( ERROR_101 );
			}

			return( true ); // player has a pair
		}
	} // end of for-loop

	return( false );
}
///////////////////////////////////////

///////////////////////////////////////
void Poker::highCard( name_t who ) const
{
	vector<bool> my_emptyArray( EMPTY_ARRAY, false );
	uint_t highestCard = ( 0 );

	if( who == PLAYER )
	{
		for( uint_t i = ( 0 ); i < my_playersHand->size( ); ++i )
		{
			if( my_playersHand->at( i )->at( 0 ) == ACE ){ my_emptyArray.at( 14 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == KING ){ my_emptyArray.at( 13 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == QUEEN ){ my_emptyArray.at( 12 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == JACK ){ my_emptyArray.at( 11 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == TEN_SUBST ){ my_emptyArray.at( 10 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == NINE ){ my_emptyArray.at( 9 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == EIGHT ){ my_emptyArray.at( 8 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == SEVEN ){ my_emptyArray.at( 7 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == SIX ){ my_emptyArray.at( 6 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == FIVE ){ my_emptyArray.at( 5 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == FOUR ){ my_emptyArray.at( 4 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == THREE ){ my_emptyArray.at( 3 ) = ( true ); }
			else if( my_playersHand->at( i )->at( 0 ) == TWO ){ my_emptyArray.at( 2 ) = ( true ); }
		
		} // end of for-loop
	}
	else if( who == DEALER )
	{
		for( uint_t i = ( 0 ); i < my_dealersHand->size( ); ++i )
		{
			if( my_dealersHand->at( i )->at( 0 ) == ACE ){ my_emptyArray.at( 14 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == KING ){ my_emptyArray.at( 13 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == QUEEN ){ my_emptyArray.at( 12 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == JACK ){ my_emptyArray.at( 11 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == TEN_SUBST ){ my_emptyArray.at( 10 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == NINE ){ my_emptyArray.at( 9 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == EIGHT ){ my_emptyArray.at( 8 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SEVEN ){ my_emptyArray.at( 7 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == SIX ){ my_emptyArray.at( 6 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FIVE ){ my_emptyArray.at( 5 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == FOUR ){ my_emptyArray.at( 4 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == THREE ){ my_emptyArray.at( 3 ) = ( true ); }
			else if( my_dealersHand->at( i )->at( 0 ) == TWO ){ my_emptyArray.at( 2 ) = ( true ); }
		
		} // end of for-loop
	}
	else
	{
		throw domain_error( ERROR_101 );
	}

	for( size_t i = (my_emptyArray.size( ) - 1 ); i >= 0; --i )
	{
		if( my_emptyArray.at( i ) == true ) 
		{
			highestCard = static_cast<uint_t>( i );
			break;
		}
    
    } // end of for-loop

	if( who == PLAYER ) { my_playersHighCard = ( highestCard ); }
	else if( who == DEALER ) { my_dealersHighCard = ( highestCard ); }
	else { throw domain_error( ERROR_101 ); }
}
///////////////////////////////////////